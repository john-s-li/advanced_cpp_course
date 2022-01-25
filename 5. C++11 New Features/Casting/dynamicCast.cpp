#include <iostream>

using namespace std;

/*
    `dynamic_cast` is useful when you don't know what the dynamic type of 
    the object is. It returns a null pointer if the object referred to doesn't 
    contain the type casted to as a base class 
*/

class Parent
{
    public:
        virtual void speak() { cout << "Parent!" << endl; }
};

class Son : public Parent
{

};


int main()
{
    Parent p;
    Son s;

    Parent* pPtr = &p;
    Son* sPtr = dynamic_cast<Son*>(pPtr); // makes no sense
    
    // @ run time, dynamic cast will check if this cast makes sense
    if(sPtr == nullptr)
    {
        cout << "Invalid pointer" << endl;
    }
    else
    {
        cout << sPtr << endl;
    }
    
    return 0;

}