#include <iostream>
#include <string>
#include <ostream>

using namespace std;

class Test
{
    public:
        Test() : _id(0), _name("")
        {}

        Test(int id, string name) : _id(id), _name(name)
        {}

        const Test& operator=(const Test& other)
        {
            _id = other._id;
            _name = other._name;
            return *this;
        }

        Test(const Test& other)
        {
            *this = other;
        }

        // Left Bit Shift << Overloading
        // can make this a friend method to access private instances
        // BUT in general, write getter methods instead
        friend ostream& operator<<(ostream& out, const Test& test)
        {
            out << "ID: " << test._id << " | " << "Name: " << test._name;
            return out;
        }

    private:
        int _id;
        string _name;
}; // end class

int main()
{
    Test test1(1, "Mike");
    cout << test1 << endl; // this is the left bit shift we are overloading

    return 0;
}