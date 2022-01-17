#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include <ostream>

using namespace std;

class ComplexNumber
{
    public:
        // Constructors, 
        ComplexNumber();
        ComplexNumber(double real, double imaginary);
        ComplexNumber(const ComplexNumber& other);
        const ComplexNumber& operator=(const ComplexNumber& other);

        double getReal() const;
        double getImaginary() const;

    private:
        double _real;
        double _imaginary;
};

ostream& operator<<(ostream& out, const ComplexNumber& num);

#endif