#include <iostream>

using namespace std;

/*
`static_cast` is used for cases where you basically want to reverse an 
implicit conversion, with a few restrictions and additions. `static_cast` 
performs no runtime checks. This should be used if you know that you refer 
to an object of a specific type, and thus a check would be unnecessary
*/

class Parent
{
    public:
        void speak() { cout << "Parent!" << endl; }
};

class Son : public Parent
{

};


int main()
{
    // static casting is a compile time that gets code working in many cases
    // up to programmer to make sure that code behavior is correct

    // Static casts can take the place of normal casting
    double pi = 3.14;
    cout << pi << endl;
    cout << int(pi) << endl;
    cout << static_cast<int>(pi) << endl;

    Parent p;
    Son s;

    // Superclass pointer can always point to subclass reference
    Parent* pPtr = &s;
    Son* sPtr = static_cast<Son*>(pPtr); // not sure why one would want to do this...but you can
    // Be careful...if Parent pointer does NOT point to a Son object, then code behavior 
    // is extremely error prone 
    cout << sPtr << endl;

    // Can also be used to Rvalue forwarding
    // say...for some reason, have a function that inputs a Rval reference but you
    // need to pass in a Lval reference
    Parent &&pR = static_cast<Parent&&>(p);
    p.speak();

    return 0;
}