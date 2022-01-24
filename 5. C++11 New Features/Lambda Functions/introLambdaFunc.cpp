#include <iostream>
#include <stdexcept>

using namespace std;

// Just some passing function pointer practice
void testFunc(double a, double b, double (*pFuncTest)(double, double))
{
    cout << "Result = " << pFuncTest(a, b) << endl;
}

int main()
{
    // Lambda expression syntax
    auto func = [](double a, double b) -> double
                { 
                    if (b == 0.0) throw invalid_argument("Cannot divide by zero.");

                    return a/b; // if only one return statement, don't need "-> double"
                                // as C++11 can infer the return type
                };

    testFunc(3,5, func);

    return 0;
}