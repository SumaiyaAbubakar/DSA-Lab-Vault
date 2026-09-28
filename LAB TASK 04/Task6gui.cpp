#include <iostream>
#include <string>
#include <windows.h>

using namespace std;


// ============================================================
// NODE
// ============================================================

class Node
{
public:
    string teamName;
    int points;
    Node *next;

    Node(string name, int pts)
    {
        teamName = name;
        points = pts;
        next = nullptr;
    }
};


// ============================================================
// CIRCULAR SINGLY LINKED LIST
// ============================================================

class CSL
{
    Node *head;
    Node *tail;

public:

    // ========================================================
    // CONSTRUCTOR
    // ========================================================

    CSL()
    {
        head = tail = nullptr;
    }


    // ========================================================
    // CHANGE CONSOLE COLOR
    // ========================================================

    void setColor(int color)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }


    // ========================================================
    // CLEAR SCREEN
    // ========================================================

    void clearScreen()
    {
        system("cls");
    }


    // ========================================================
    // PAUSE
    // ========================================================

    void pause()
    {
        Sleep(1000);
    }


    // ========================================================
    // VOICE
    // ========================================================

    void speak(string message)
    {
        // Replace apostrophe with two apostrophes
        // because PowerShell uses ' ' for strings.
        string safeMessage = "";

        for (int i = 0; i < message.length(); i++)
        {
            if (message[i] == '\'')
            {
                safeMessage += "''";
            }
            else
            {
                safeMessage += message[i];
            }
        }

        string command =
            "powershell -Command \""
            "Add-Type -AssemblyName System.Speech; "
            "$voice = New-Object System.Speech.Synthesis.SpeechSynthesizer; "
            "$voice.Speak('" + safeMessage + "');"
            "\"";

        system(command.c_str());
    }


    // ========================================================
    // SEARCH
    // ========================================================

    bool search(string name)
    {
        if (head == nullptr)
        {
            return false;
        }

        Node *temp = head;

        do
        {
            if (temp->teamName == name)
            {
                return true;
            }

            temp = temp->next;

        } while (temp != head);

        return false;
    }


    // ========================================================
    // ADD TEAM
    // ========================================================

    void addTeam(string name, int pts)
    {
        if (pts < 0 || pts > 150)
        {
            cout << "Invalid points. Points must be between 0 and 150.\n";
            return;
        }

        if (search(name))
        {
            cout << "Duplicate team name. Team not added.\n";
            return;
        }

        Node *newNode = new Node(name, pts);

        if (head == nullptr)
        {
            head = tail = newNode;

            newNode->next = head;

            cout << "Team added successfully.\n";

            return;
        }

        tail->next = newNode;

        tail = newNode;

        tail->next = head;

        cout << "Team added successfully.\n";
    }


    // ========================================================
    // DISPLAY TEAMS
    // ========================================================

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;

        cout << "\n----------------------------------------\n";

        do
        {
            cout << temp->teamName
                 << " - Points: "
                 << temp->points
                 << endl;

            temp = temp->next;

        } while (temp != head);

        cout << "----------------------------------------\n";
    }


    // ========================================================
    // DISPLAY CIRCULAR ORDER
    // ========================================================

    void displayCircularOrder()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *temp = head;

        cout << "\nCurrent Circular Order:\n\n";

        do
        {
            cout << "[ "
                 << temp->teamName
                 << " : "
                 << temp->points
                 << " ]";

            if (temp->next != head)
            {
                cout << " -> ";
            }

            temp = temp->next;

        } while (temp != head);

        cout << " -> HEAD\n";
    }


    // ========================================================
    // REMOVE TEAM
    // ========================================================

    void removeTeam(string name)
    {
        if (head == nullptr)
        {
            cout << "\nList is empty.\n";
            return;
        }

        Node *temp = head;
        Node *prev = tail;

        do
        {
            if (temp->teamName == name)
            {
                // Only one node
                if (temp == head && temp == tail)
                {
                    delete temp;

                    head = tail = nullptr;

                    cout << "\nTeam removed.\n";

                    return;
                }


                // Removing head
                if (temp == head)
                {
                    head = head->next;

                    tail->next = head;

                    delete temp;

                    cout << "\nTeam removed.\n";

                    return;
                }


                // Removing middle or tail
                prev->next = temp->next;


                // Removing tail
                if (temp == tail)
                {
                    tail = prev;

                    tail->next = head;
                }

                delete temp;

                cout << "\nTeam removed.\n";

                return;
            }

            prev = temp;
            temp = temp->next;

        } while (temp != head);

        cout << "\nTeam not found.\n";
    }


    // ========================================================
    // FIND HIGHEST POINT TEAM
    // ========================================================

    Node *findHighestScoreTeam()
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        Node *highest = head;

        Node *temp = head->next;

        while (temp != head)
        {
            if (temp->points > highest->points)
            {
                highest = temp;
            }

            temp = temp->next;
        }

        return highest;
    }


    // ========================================================
    // FIND LOWEST TEAM STARTING FROM A PARTICULAR NODE
    // ========================================================

    Node *findLowestFrom(Node *start, Node *exclude)
    {
        Node *lowest = nullptr;

        Node *temp = start;

        do
        {
            if (temp != exclude)
            {
                if (lowest == nullptr ||
                    temp->points < lowest->points)
                {
                    lowest = temp;
                }
            }

            temp = temp->next;

        } while (temp != start);

        return lowest;
    }


    // ========================================================
    // UPDATE POINTS
    // ODD POSITION  -> -20
    // EVEN POSITION -> +10
    // ========================================================

    void updatePoints()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *temp = head;

        int position = 1;

        do
        {
            if (position % 2 == 1)
            {
                temp->points = temp->points - 20;
            }
            else
            {
                temp->points = temp->points + 10;
            }


            // Minimum 0
            if (temp->points < 0)
            {
                temp->points = 0;
            }


            // Maximum 150
            if (temp->points > 150)
            {
                temp->points = 150;
            }


            temp = temp->next;

            position++;

        } while (temp != head);
    }


    // ========================================================
    // COUNT TEAMS
    // ========================================================

    int countTeams()
    {
        if (head == nullptr)
        {
            return 0;
        }

        int count = 0;

        Node *temp = head;

        do
        {
            count++;

            temp = temp->next;

        } while (temp != head);

        return count;
    }


    // ========================================================
    // COUNTING ANIMATION
    // ========================================================

    Node *countingAnimation(Node *start, int count)
    {
        Node *selected = start;

        cout << "\nCounting begins...\n\n";

        Sleep(700);

        for (int i = 1; i <= count; i++)
        {
            setColor(14);

            cout << "Count " << i
                 << " -> "
                 << selected->teamName
                 << endl;

            Beep(700, 250);

            Sleep(400);

            selected = selected->next;
        }

        // We moved one extra step after the last count.
        // Therefore go back to the actual selected node.
        selected = selected == start
                       ? start
                       : selected;

        // The loop above leaves selected at the node AFTER
        // the node where count ended.
        Node *actual = start;

        for (int i = 1; i < count; i++)
        {
            actual = actual->next;
        }

        return actual;
    }


    // ========================================================
    // COUNTDOWN
    // ========================================================

    void countdown()
    {
        cout << endl;

        setColor(12);
        cout << "\n\n\t\t3";
        Beep(900, 400);
        Sleep(500);

        clearScreen();

        setColor(14);
        cout << "\n\n\t\t2";
        Beep(800, 400);
        Sleep(500);

        clearScreen();

        setColor(13);
        cout << "\n\n\t\t1";
        Beep(700, 400);
        Sleep(500);

        clearScreen();

        setColor(12);
        cout << "\n\n\t\tELIMINATION!";
        Beep(1000, 800);

        Sleep(1000);

        setColor(7);
    }


    // ========================================================
    // CHAMPION SCREEN
    // ========================================================

    void championScreen()
    {
        clearScreen();

        setColor(14);

        cout << "\n\n";
        cout << "============================================\n";
        cout << "              FIFA WORLD CUP\n";
        cout << "             KNOCKOUT CHALLENGE\n";
        cout << "============================================\n\n";

        cout << "              CHAMPION!\n\n";

        cout << "              " << head->teamName << endl;

        cout << "\n              Points: "
             << head->points << endl;

        cout << "\n============================================\n";

        setColor(7);

        speak("Congratulations. "
              + head->teamName
              + " is the FIFA World Cup Knockout Challenge champion.");

        Beep(1000, 500);
        Beep(1200, 500);
        Beep(1400, 700);

        Sleep(2000);
    }


    // ========================================================
    // KNOCKOUT CHALLENGE
    // ========================================================

    void knockOutChallenge()
    {
        // ----------------------------------------------------
        // EMPTY LIST
        // ----------------------------------------------------

        if (head == nullptr)
        {
            cout << "\nNo teams available.\n";
            return;
        }


        // ----------------------------------------------------
        // ONE TEAM
        // ----------------------------------------------------

        if (head == tail)
        {
            clearScreen();

            cout << "\nOnly one team exists.\n";

            cout << "Champion: "
                 << head->teamName
                 << endl;

            speak("There is only one team. "
                  + head->teamName
                  + " is the champion.");

            return;
        }


        // ----------------------------------------------------
        // USER INPUT
        // ----------------------------------------------------

        string startTeam;

        int count;

        cout << "\nEnter starting team: ";
        cin >> startTeam;

        cout << "Enter counting number: ";
        cin >> count;


        // ----------------------------------------------------
        // INVALID COUNT
        // ----------------------------------------------------

        if (count <= 0)
        {
            cout << "Counting number must be greater than 0.\n";
            return;
        }


        // ----------------------------------------------------
        // FIND STARTING TEAM
        // ----------------------------------------------------

        Node *current = head;

        bool found = false;

        do
        {
            if (current->teamName == startTeam)
            {
                found = true;
                break;
            }

            current = current->next;

        } while (current != head);


        if (!found)
        {
            cout << "Starting team not found.\n";
            return;
        }


        // ----------------------------------------------------
        // START GAME
        // ----------------------------------------------------

        clearScreen();

        setColor(11);

        cout << "\n============================================\n";
        cout << "       FIFA WORLD CUP KNOCKOUT CHALLENGE\n";
        cout << "============================================\n";

        setColor(7);

        cout << "\nStarting Team: "
             << startTeam
             << endl;

        cout << "Counting Number: "
             << count
             << endl;

        speak("Welcome to the FIFA World Cup Knockout Challenge.");

        Sleep(1500);


        // ----------------------------------------------------
        // ROUND NUMBER
        // ----------------------------------------------------

        int round = 1;


        // ====================================================
        // MAIN KNOCKOUT LOOP
        // ====================================================

        while (head != tail)
        {
            clearScreen();

            setColor(11);

            cout << "\n============================================\n";
            cout << "                 ROUND "
                 << round
                 << endl;
            cout << "============================================\n";

            setColor(7);

            cout << "\nStarting count from: "
                 << current->teamName
                 << endl;

            displayCircularOrder();

            Sleep(1500);


            // ------------------------------------------------
            // COUNTING
            // ------------------------------------------------

            Node *selected = countingAnimation(current, count);


            // ------------------------------------------------
            // SHOW SELECTED TEAM
            // ------------------------------------------------

            setColor(14);

            cout << "\nSelected Team: "
                 << selected->teamName
                 << endl;

            cout << "Points: "
                 << selected->points
                 << endl;

            setColor(7);

            speak("The selected team is "
                  + selected->teamName);


            Sleep(1000);


            // ------------------------------------------------
            // FIND HIGHEST TEAM
            // ------------------------------------------------

            Node *highest = findHighestScoreTeam();

            Node *eliminated = nullptr;

            Node *eliminatedPrev = nullptr;


            // ------------------------------------------------
            // SELECTED TEAM HAS HIGHEST POINTS
            // ------------------------------------------------

            if (selected->points == highest->points)
            {
                setColor(12);

                cout << "\nSelected team "
                     << selected->teamName
                     << " cannot be eliminated because it has "
                        "the highest points.\n";

                setColor(7);

                speak(selected->teamName
                      + " is protected because it has the highest points.");


                Sleep(1200);


                // Find lowest EXCLUDING selected
                eliminated = findLowestFrom(current, selected);


                // Find previous node
                eliminatedPrev = eliminated;

                while (eliminatedPrev->next != eliminated)
                {
                    eliminatedPrev = eliminatedPrev->next;
                }


                cout << "\nInstead, the lowest-point team will be eliminated.\n";

                cout << "Lowest team: "
                     << eliminated->teamName
                     << " with "
                     << eliminated->points
                     << " points.\n";

                speak("The lowest points team will be eliminated.");
            }


            // ------------------------------------------------
            // NORMAL ELIMINATION
            // ------------------------------------------------

            else
            {
                eliminated = selected;

                eliminatedPrev = eliminated;

                while (eliminatedPrev->next != eliminated)
                {
                    eliminatedPrev = eliminatedPrev->next;
                }
            }


            Sleep(1000);


            // ------------------------------------------------
            // COUNTDOWN
            // ------------------------------------------------

            countdown();


            // ------------------------------------------------
            // SAVE NEXT START
            // BEFORE DELETING NODE
            // ------------------------------------------------

            Node *nextStart = eliminated->next;


            // ------------------------------------------------
            // DELETE NODE
            // ------------------------------------------------

            eliminatedPrev->next = eliminated->next;


            // If deleting head
            if (eliminated == head)
            {
                head = eliminated->next;
            }


            // If deleting tail
            if (eliminated == tail)
            {
                tail = eliminatedPrev;
            }


            // Maintain circular structure
            tail->next = head;


            // ------------------------------------------------
            // ANNOUNCE ELIMINATION
            // ------------------------------------------------

            clearScreen();

            setColor(12);

            cout << "\n============================================\n";
            cout << "             TEAM ELIMINATED\n";
            cout << "============================================\n";

            cout << "\n"
                 << eliminated->teamName
                 << " has been eliminated!\n";

            cout << "Points before elimination: "
                 << eliminated->points
                 << endl;

            setColor(7);

            speak(eliminated->teamName
                  + " has been eliminated.");


            // Delete node from memory
            delete eliminated;


            Sleep(1500);


            // ------------------------------------------------
            // UPDATE POINTS
            // ------------------------------------------------

            cout << "\nUpdating points of remaining teams...\n";

            speak("Updating points of the remaining teams.");

            Sleep(800);

            updatePoints();


            // ------------------------------------------------
            // SHOW UPDATED TEAMS
            // ------------------------------------------------

            clearScreen();

            setColor(10);

            cout << "\n============================================\n";
            cout << "          AFTER ROUND "
                 << round
                 << endl;
            cout << "============================================\n";

            setColor(7);

            cout << "\nUpdated Points:\n";

            display();


            cout << "\n";

            displayCircularOrder();


            // ------------------------------------------------
            // NEXT ROUND START
            // ------------------------------------------------

            current = nextStart;


            // ------------------------------------------------
            // IF NEXT START WAS THE DELETED NODE'S NEXT
            // AND IT IS STILL VALID
            // ------------------------------------------------

            if (current == nullptr)
            {
                current = head;
            }


            speak("Round "
                  + to_string(round)
                  + " completed.");

            Sleep(2000);

            round++;
        }


        // ====================================================
        // CHAMPION
        // ====================================================

        championScreen();
    }
};


// ============================================================
// MAIN
// ============================================================

int main()
{
    CSL list;

    int choice;


    do
    {
        system("cls");

        cout << "\n";
        cout << "============================================\n";
        cout << "       FIFA WORLD CUP KNOCKOUT CHALLENGE\n";
        cout << "============================================\n";

        cout << "\n1. Add Team";
        cout << "\n2. Remove Team";
        cout << "\n3. Search Team";
        cout << "\n4. Display Teams";
        cout << "\n5. Start Knockout Challenge";
        cout << "\n6. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;


        // ====================================================
        // ADD
        // ====================================================

        if (choice == 1)
        {
            string name;

            int points;

            cout << "\nEnter team name: ";
            cin >> name;

            cout << "Enter points: ";
            cin >> points;

            list.addTeam(name, points);

            Sleep(1000);
        }


        // ====================================================
        // REMOVE
        // ====================================================

        else if (choice == 2)
        {
            string name;

            cout << "\nEnter team name to remove: ";
            cin >> name;

            list.removeTeam(name);

            Sleep(1000);
        }


        // ====================================================
        // SEARCH
        // ====================================================

        else if (choice == 3)
        {
            string name;

            cout << "\nEnter team name to search: ";
            cin >> name;

            if (list.search(name))
            {
                cout << "\nTeam found.\n";
            }
            else
            {
                cout << "\nTeam not found.\n";
            }

            Sleep(1000);
        }


        // ====================================================
        // DISPLAY
        // ====================================================

        else if (choice == 4)
        {
            list.display();

            cout << "\n";

            system("pause");
        }


        // ====================================================
        // START KNOCKOUT
        // ====================================================

        else if (choice == 5)
        {
            list.knockOutChallenge();

            cout << "\n";

            system("pause");
        }


        // ====================================================
        // EXIT
        // ====================================================

        else if (choice == 6)
        {
            cout << "\nProgram ended.\n";
        }


        // ====================================================
        // INVALID CHOICE
        // ====================================================

        else
        {
            cout << "\nInvalid choice.\n";

            Sleep(1000);
        }

    } while (choice != 6);


    return 0;
}