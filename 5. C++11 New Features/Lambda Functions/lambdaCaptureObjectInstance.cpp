#include <iostream>

using namespace std;

class Test
{
    public:
        void runTest()
        {
            int x3 = 3;
            int x4 = 4;

            // capturing "this" will give lambda function access 
            // to all instance variable references
            [x3, x4, this]()
            { 
                x1 = 10;
                x2 = 20;
                cout << "Total sum = " << (x1+x2+x3+x4) << endl;
            }();
        }

    private:
        int x1 = 1;
        int x2 = 2;
};

int main()
{   
    Test t;
    t.runTest();

    return 0;
}