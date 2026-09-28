#include <iostream>
using namespace std;

class Node
{
public:
    string teamName;
    int points;
    Node *next;
    Node *prev;

    Node(string name, int pts)
    {
        teamName = name;
        points = pts;
        next = nullptr;
        prev = nullptr;
    }
};

class CSL
{
    Node *head;
    Node *tail;

public:
    CSL()
    {
        head = tail = nullptr;
    }

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
        }

        while (temp != head);

        return false;
    }

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
            newNode->prev = tail;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        tail->next = head;
        head->prev = tail;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;

        do
        {
            cout << temp->teamName << " - Points: " << temp->points << endl;

            temp = temp->next;

        } while (temp != head);
    }

    void removeTeam(string name)
    {
        if (head == nullptr)
        {
            cout << "\nList is empty.";
            return;
        }

        Node *temp = head;

        do
        {
            if (temp->teamName == name)
            {
                if (temp == head && temp == tail)
                {
                    delete temp;
                    head = tail = nullptr;
                    cout << "\nTeam removed.\n";
                    return;
                }

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (temp == head)
                {
                    head = temp->next;
                }

                if (temp == tail)
                {
                    tail = temp->prev;
                }

                tail->next = head;
                head->prev = tail;

                delete temp;

                cout << "Team removed.\n";
                return;
            }

            temp = temp->next;
        }

        while (temp != head);

        cout << "\nTeam not found.";
    }

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

    Node *findLowestScoreTeam()
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        Node *Lowest = head;
        Node *temp = head->next;

        while (temp != head)
        {
            if (temp->points < Lowest->points)
            {
                Lowest = temp;
            }

            temp = temp->next;
        }

        return Lowest;
    }

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

            if (temp->points < 0)
            {
                temp->points = 0;
            }

            if (temp->points > 150)
            {
                temp->points = 150;
            }

            temp = temp->next;
            position++;
        }

        while (temp != head);
    }

    // Node *findLowestFrom(Node *start)
    // {
    //     Node *lowest = start;
    //     Node *temp = start->next;

    //     do
    //     {
    //         if (temp->points < lowest->points)
    //         {
    //             lowest = temp;
    //         }

    //         temp = temp->next;

    //     }

    //     while (temp != start);

    //     return lowest;
    // }

    void knockOutChallenge()
    {
        if (head == nullptr)
        {
            cout << "No teams available.\n";
            return;
        }

        if (head == tail)
        {
            cout << "Only one team exists.\n";
            cout << "Champion: " << head->teamName << endl;
            return;
        }

        string startTeam;
        int count;

        cout << "Enter starting team: ";
        cin >> startTeam;

        cout << "Enter counting number: ";
        cin >> count;

        if (count <= 0)
        {
            cout << "Counting number must be greater than 0.\n";
            return;
        }

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

        bool forward = true;

        while (head != tail)
        {
            Node *selected = current;

            for (int i = 1; i < count; i++)
            {
                if (forward)
                {
                    selected = selected->next;
                }
                else
                {
                    selected = selected->prev;
                }
            }

            Node *highest = findHighestScoreTeam();

            Node *eliminated;

            bool protectionTriggered = false;

            if (selected->points == highest->points)
            {
                cout << "Selected team " << selected->teamName
                     << " cannot be eliminated because it has the highest points.\n";
                eliminated = findLowestScoreTeam();
                protectionTriggered = true;
            }
            else
            {
                eliminated = selected;
            }

            Node *nextForward = eliminated->next;
            Node *nextBackward = eliminated->prev;

            eliminated->prev->next = eliminated->next;
            eliminated->next->prev = eliminated->prev;

            // Node *nextStart = eliminated->next;

            // eliminatedPrev->next = eliminated->next;

            if (eliminated == head)
            {
                head = eliminated->next;
            }

            if (eliminated == tail)
            {
                tail = eliminated->prev;
            }

            tail->next = head;
            head->prev = tail;

            cout << "Eliminated team: " << eliminated->teamName << endl;

            delete eliminated;

            if (protectionTriggered)
            {
                forward = !forward;
            }

            if (forward)
            {
                current = nextForward;
            }
            else
            {
                current = nextBackward;
            }

            // current = nextStart;

            updatePoints();

            display();
        }

        cout << "\nFIFA Knockout Challenge Champion: " << head->teamName << endl;
    }
};

int main()
{
    CSL list;

    int choice;

    do
    {
        cout << "\n===== FIFA WORLD CUP KNOCKOUT CHALLENGE =====\n";
        cout << "1. Add Team\n";
        cout << "2. Remove Team\n";
        cout << "3. Search Team\n";
        cout << "4. Display Teams\n";
        cout << "5. Start Knockout Challenge\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string name;
            int points;

            cout << "Enter team name: ";
            cin >> name;

            cout << "Enter points: ";
            cin >> points;

            list.addTeam(name, points);
        }

        else if (choice == 2)
        {
            string name;

            cout << "Enter team name to remove: ";
            cin >> name;

            list.removeTeam(name);
        }

        else if (choice == 3)
        {
            string name;

            cout << "Enter team name to search: ";
            cin >> name;

            if (list.search(name))
            {
                cout << "Team found.\n";
            }
            else
            {
                cout << "Team not found.\n";
            }
        }

        else if (choice == 4)
        {
            list.display();
        }

        else if (choice == 5)
        {
            list.knockOutChallenge();
        }

        else if (choice == 6)
        {
            cout << "Program ended.\n";
        }

        else
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}