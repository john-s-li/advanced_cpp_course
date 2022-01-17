#include "ComplexNumber.h"

using namespace std;

ComplexNumber::ComplexNumber() : _real(0), _imaginary(0)
{}

ComplexNumber::ComplexNumber(double real, double imaginary) 
    : _real(real), _imaginary(imaginary)
{}

ComplexNumber::ComplexNumber(const ComplexNumber& other)
{
    *this = other;
}

const ComplexNumber& ComplexNumber::operator=(const ComplexNumber& other)
{
    _real = other._real;
    _imaginary = other._imaginary;
    return *this;
}

double ComplexNumber::getReal() const
{
    return _real;
}

double ComplexNumber::getImaginary() const
{
    return _imaginary;
}

ostream& operator<<(ostream& out, const ComplexNumber& num)
{
    out << num.getReal() << " + (" << num.getImaginary() << ")i";
    return out;
}