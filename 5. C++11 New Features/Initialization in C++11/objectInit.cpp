#include <iostream>
#include <ostream>
#include <string>

using namespace std;

class Test
{
    public:
        Test() = default; // need this if there is a constructor with arguments when private
                          // variables are initialized in declaration
                          // default = default c++ shallow copy implementation
        Test(const Test &other) = delete; // delete keyword means no copy constructor
        Test& operator=(const Test &other) = default;
        Test(int id) : _id(id) {} 
        friend ostream& operator<<(ostream& out, const Test& test);

    private:
        // In C++11, can initialize private variables inline
        int _id = 3;
        string _name = "John";
};

ostream& operator<<(ostream &out, const Test &test)
{
    out << "ID: " << test._id << " | " << "Name: " << test._name;
    return out;
}

int main()
{
    Test myTest;
    cout << myTest << endl;

    Test myTest1(5);
    cout << myTest1 << endl;

    // Should invoke an error when buiding
    // Test myTest2(myTest);

    // No error
    Test myTest2;
    myTest2 = myTest1;
    cout << myTest2 << endl;

    return 0;
}