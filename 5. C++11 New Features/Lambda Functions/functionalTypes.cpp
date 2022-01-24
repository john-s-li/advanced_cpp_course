#include <iostream>
#include <functional>
#include <string>

using namespace std;

// functional types describe callable function types
// they are the "int" or "double" equivalents for functions
// alternative to passing a function pointer

void run(function<bool(string&)> func, string &testString)
{
    cout << boolalpha << func(testString) << endl;
}

// Functor
class checkFunc
{
    public:
        bool operator()(const string &test)
        {
            return test == "dog";
        }
};

int main()
{
    string testString = "cat";

    // here, "auto" refers the lambda functional type
    auto func1 = [](const string &test)->bool{ return test == "cat"; };
    checkFunc func2;

    run(func1, testString);
    run(func2, testString);

    return 0;
}