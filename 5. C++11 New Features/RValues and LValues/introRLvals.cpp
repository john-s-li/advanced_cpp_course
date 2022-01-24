#include <iostream>

using namespace std;

int main()
{
    // Lvalue is anything that can be set to an address of a variable or object
    // Rvalue is anything that CANNOT be assigned an address i.e. the number 7

    // Lvalue = Rvalue
    int x1 = 7;

    int* xPtr = &x1; // x1 is an Lvalue because x1 has an address
    cout << "Value of pointer = " << *xPtr << endl;

    // NOT VALID
    // xPtr = &7; // 7 is an RValue and therefore does NOT have an address

    int* xPtr2 = &(++x1); // ++x1 increments x1 first then returns x1 with its new incremented value
    cout << "Value of 2nd pointer = " << *xPtr2;

    // int* xPtr3 = &(x1++); // NOT VALID since x1++ increments x1 but returns the original value

    // Work around for Lvalues ###########################################################
    // --> can actually bind const Lvalue references to Rvalues
    // Not for variables but works for classes if a non-reference object is returned
    // from a function
    // i.e. Test &Test2 = getTest() does not work BUT 
    //      const Test &Test2 = getTest does indeed work

    // Rvalue references #################################################################
    // can be binded to Rvalues --> syntax is && in front of a name
    // used for avoiding unnecessary forwarding 

    return 0;
}