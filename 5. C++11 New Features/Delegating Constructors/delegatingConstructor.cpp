#include <iostream>
#include <string>

using namespace std;

class ParentTest
{
    public:
        ParentTest() : ParentTest("delegate") // how to call a delegate constructor
                                              // first delegate initializes all members
                                              // BE CAREFUL WITH RECURSION since C++ does not check
        {
            cout << "Parent Class Constructor\n";
        }

        ParentTest(string text)
        {
            _text = text;
            _num = 5;
            cout << "Parent Parameter Class Constructor\n";
        }

    private:
        // for children to access this, will need public access functions
        int _num;
        string _text;

    protected:
        bool _boolean{true};

};

class ChildTest : public ParentTest
{
    public:
        ChildTest()
        {  
            // In order for a derived class to access members of a parent class,
            // such variables must be declared as protected
            cout << "Child Class Constructor\n";
            _boolean = false;
            cout << boolalpha << _boolean << endl;
        }

};

int main()
{
    ParentTest p;
    cout << "Making child...\n";
    ChildTest c;

    return 0;
}