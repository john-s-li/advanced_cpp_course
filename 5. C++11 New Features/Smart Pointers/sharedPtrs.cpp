#include <iostream>
#include <memory>

using namespace std;

class Test
{
    public:
        Test()  { cout << "Created\n"; }
        ~Test() { cout << "Deleted\n"; }
};

int main()
{
    shared_ptr<Test> ptr1(nullptr);

    {
        // this goes out of scope at the end of the curly braces
        auto ptr2 = make_shared<Test>();
        
        // this ptr goes out of scope outside of the curly braces
        // can see that object "survives" until end of program
        ptr1 = ptr2;
    }

    cout << "Finished" << endl;
    return 0;
}