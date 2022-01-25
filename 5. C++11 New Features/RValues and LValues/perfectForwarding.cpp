#include <iostream>

using namespace std;

/*
    Not really used a lot but mentioned a lot in C++ literature
*/

template <class T>
void call(T&& arg) // takes an Rvalue
{
    check(arg); // in this context for check, arg is an Lvalue
    check(static_cast<T>(arg)); // "perfectly forward" the inferred type
    check(forward<T>(arg)); // same syntax as previous line
}

class Test
{

};

void check(Test& test)
{
    cout << "Lvalue\n";
};

void check(Test&& test)
{
    cout << "Rvalue\n";
}


int main()
{
    Test t;

    cout << "Passing in Rval\n";
    call(Test()); // pass in Rval ref
    cout << "Passing in Lval\n";
    call(t); // pass in Lval ref

    return 0;
}