#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

class Test
{
    public:
        int add(int a, int b, int c)
        {   
            cout << "a = " << a << " | b = " << b << " | c = " << c << endl;
            return a + b + c;
        }

};

int add(int a, int b, int c)
{
    cout << "a = " << a << " | b = " << b << " | c = " << c << endl;
    return a + b + c;
}

int main()
{
    auto calculate = bind(add, _1, _2, _3);
    cout << calculate(10,20,30) << endl;

    auto calculate2 = bind(add, _1, 100, _2);
    cout << calculate2(10,30) << endl;

    // Can also bind to methods as well
    Test t;
    auto calculate3 = bind(&Test::add, t, _1, 50, 200);
    cout << calculate3(25) << endl;

    return 0;
}