#include <iostream>
#include <string>

using namespace std; 

void displayAge(string name, int age)
{
    cout << name << " : " << age << endl;
}

int main()
{
    const string NAME = "John";
    const int AGE = 25;

    // Normal function call
    cout << "Normal function call - - -" << endl;
    displayAge(NAME, AGE);

    // Function pointer calling
    // return type of function (*name of pointer)(argument types) = name of actual function
    void (*functionPtr)(string, int) = displayAge; 
    // NOTE: function names are pointers
    cout << "Function call with pointer - - -" << endl;
    functionPtr(NAME, AGE);

    return 0;
}