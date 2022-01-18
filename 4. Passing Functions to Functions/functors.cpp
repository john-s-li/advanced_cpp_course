#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* 
    Functors can be used if you want to use function pointers
    but also need access to some private variables or keep track
    of a state
*/ 

// Trivial example 
struct Test // Abstract class
{
    virtual bool operator()(const string &text) = 0; // will overload () operator
    virtual ~Test() {} // need a destructor when there are sub-classes
};

// This is the functor
struct LionTest : public Test
{
    virtual bool operator()(const string &text)
    {
        return (text == "lion");
    }
};

struct CatTest : public Test
{
    virtual bool operator()(const string &text)
    {
        return (text == "cat");
    }
};

void check(const string &text, Test& test) // pass in a functor instead of a function ptr
{
    if(test(text)) cout << "Text matches!\n";
    else cout << "No match.\n";
}


int main()
{
    vector<Test*> testPtrs;
    LionTest lTest;
    CatTest  cTest;

    testPtrs.push_back(&lTest);
    testPtrs.push_back(&cTest);

    for(int i = 0; i < testPtrs.size(); ++i)
    {
        check("lion", *testPtrs[i]); // have to deference first since check function
                                     // takes in a Test& as argument
                                     // NOTE: cannot take in a Test* since pointers
                                     // do not have a () operator
    }

    return 0;
}