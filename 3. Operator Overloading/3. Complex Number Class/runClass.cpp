#include "ComplexNumber.h"
#include <iostream>

int main()
{
    int real;
    int imag;

    cout << "Enter the real value: " << endl;
    cin >> real;
    cout << "Enter the imaginary value: " << endl;
    cin >> imag;

    ComplexNumber num1(real, imag);
    cout << "Your complex number is " << num1 << endl;

    return 0;
}