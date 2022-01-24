#include <iostream>

using namespace std;

int main()
{
    int x1 = 1;
    int x2 = 2;
    int x3 = 3;

    // 1. Capture x1 and x2 by value
    [x1, x2](){ cout << x1 << " , " << x2 << endl; }();

    // 2. Capture all local variables by value
    [=](){ cout << x1 << " , " << x2 << " , " << x3 << endl; }();

    // 3. Capture all variables by value but x3 by referece
    [=, &x3](){ x3=7; cout << x1 << " , " << x2 << " , " << x3 << endl; }();  

    // 4. Capture all local variables by reference
    [&](){ x1=3; x2=5; x3=9; cout << x1 << " , " << x2 << " , " << x3 << endl; }();

    // 5. Capture all variables by value but x1 by value
    [&, x1](){x2=10; x3=50; cout << x1 << " , " << x2 << " , " << x3 << endl; }();

    return 0;
}