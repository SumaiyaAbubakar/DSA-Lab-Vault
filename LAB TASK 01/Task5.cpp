#include<iostream>
using namespace std;

class Product
{
    string product_name;
    int *quantity;

    public:
    Product(string name, int qty)
    {
        product_name=name;
        quantity=new int;
        *quantity=qty;
    }

    Product(const Product& orig)
    {
        product_name=orig.product_name;
        quantity=new int;
        *quantity=*(orig.quantity);
    }

    Product& operator=(const Product& orig)
    {
        if (this != &orig)
        {
            delete quantity;

            product_name=orig.product_name;

            quantity = new int;

            *quantity=*(orig.quantity);
        }

        return *this;
    }

    void display()
    {
        cout<<"Product name : "<<product_name<<endl;
        cout<<"Quantity : "<<*quantity<<endl;
    }

    void setQuantity(int qty)
    {
        *quantity=qty;
    }

    ~Product()
    {
        delete quantity;
    }
};

int main()
{
    Product obj1("Laptop", 5);

    cout << "Original Object:\n";
    obj1.display();


    // Copy constructor
    Product obj2(obj1);

    cout << "\nObject 2 after copying Object 1:\n";
    obj2.display();

    // Modify copied object
    obj2.setQuantity(10);

    cout << "\nAfter modifying Object 2:\n";

    cout << "Object 1:\n";
    obj1.display();

    cout << "\nObject 2:\n";
    obj2.display();

    // Assignment operator
    Product obj3("Mobile", 2);

    cout << "\nObject 3 before assignment:\n";
    obj3.display();

    obj3 = obj1;

    cout << "\nObject 3 after assigning Object 1 to Object 3:\n";
    obj3.display();

    return 0;
}