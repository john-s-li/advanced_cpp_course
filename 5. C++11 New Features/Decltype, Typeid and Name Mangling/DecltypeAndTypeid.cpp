#include <iostream>
#include <string>
#include <typeinfo> // needed for typeid

using namespace std;

int main()
{
    int myInt;
    double myDouble;
    string myString;

    cout << typeid(myInt).name() << endl;
    cout << typeid(myDouble).name() << endl;
    cout << typeid(myString).name() << endl; // will output some name mangling depending on compiler

    // Can also use decltype to declare variable types of existing variables
    decltype(myString) newString;
    cout << typeid(newString).name() << endl;

    return 0;
}