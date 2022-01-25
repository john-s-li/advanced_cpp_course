#include <iostream>

using namespace std;

/*
    Reinterpret casts are used for the rare case when one needs to completely
    cast the type of one pointer to another type 
*/

class Parent
{
    public:
        virtual void speak() { cout << "Parent!" << endl; }
};

class Son : public Parent
{};

class Daughter : public Parent
{};


int main()
{
    Parent p;
    Son s;
    Daughter d;

    Parent* pPtr = &s;
    Daughter* dPtr = reinterpret_cast<Daughter*>(pPtr);

    if(dPtr == nullptr)
    {
        cout << "Invalid pointer" << endl;
    }
    else
    {
        cout << dPtr << endl;
    }
    
    return 0;

}