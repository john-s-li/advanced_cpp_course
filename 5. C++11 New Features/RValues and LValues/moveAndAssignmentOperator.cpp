#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

const int SIZE = 100;

// For more information:
// https://www.fluentcpp.com/2018/02/06/understanding-lvalues-rvalues-and-their-references/

class Test
{
    public:
        // Default constructor
        Test()
        {
            _pBuffer = new int[SIZE]{}; // {} initializes everything to 0
        }

        // Copy constructor
        Test(const Test& other) : Test()
        {
            memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
        }
        
        // Destructor
        ~Test()
        {
            delete[] _pBuffer;
        }

        // Assignment operator
        Test& operator=(const Test& other)
        {
            memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));

            return *this;
        }

        // Move and Assignement ########################################
        Test(Test&& other) // pass in an Rval reference
        {
            cout << "Move constructor.\n";
            memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
            other._pBuffer = nullptr;
        }

        Test& operator=(Test&& other)
        {
            cout << "Move assignement.\n";
            memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
            other._pBuffer = nullptr;

            return *this;
        }
        // ############################################################# 

    private:
        int* _pBuffer = nullptr;
};

// Trivial function for example purposes
Test getTest()
{
    return Test(); // returns an RValue (NOT a Lvalue reference)
}


int main()
{
    vector<Test> myVec;
    myVec.push_back(Test()); // push back a Rval

    // figure out why there is a segmentation fault
    Test t;
    t = getTest();

    return 0;
}