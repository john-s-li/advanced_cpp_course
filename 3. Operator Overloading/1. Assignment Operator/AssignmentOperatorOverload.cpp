#include <iostream>
#include <string>

using namespace std;

class Test
{
    public:
        Test() : _id(0), _name("")
        {}

        Test(int id, string name) : _id(id), _name(name)
        {}

        void print() const
        {
            cout << "ID: " << _id << " and name: " << _name << endl;
        }

        // Overloading of assignment operator
        const Test& operator=(const Test& other)
        {
            cout << "Assignment overload. . .\n";
            _id = other._id;
            _name = other._name;
            return *this;
        }

        // Copy constructor
        Test(const Test& other)
        {
            cout << "Copy constructor. . .\n";
            _id = other._id;
            _name = other._name;
        }

        // NOTE: in C++, good practice to make destructor, overloaded assignment operator
        // and copy constructor (Rule of 3) --> if deep copy, then default destructor will
        // delete the "chain" of assignments

    private:
        int _id;
        string _name;
}; // end class

int main()
{
    Test test1(1, "Mike");
    Test test2(2, "Jane");

    cout << "Test 1:\n";
    test1.print();

    cout << "Test 2:\n";
    test2.print();

    // C++ has a default shallow copy assignment operator
    // to make deep copy, need to implement unique overloaded
    // assignment operator
    test2 = test1; 
    cout << "Test 2:\n";
    test2.print();

    cout << "Test 3:\n";
    Test test3 = test1;
    test3.print();

    return 0;
}