#include <iostream>

using namespace std;

int main()
{
    int numCats = 5;

    // need the "mutable" keyword to modify this variable within lambda function body
    // without having to pass by a reference
    [numCats]() mutable { 
                        numCats=10; 
                        cout << "In Lambda, there are " << numCats << " cats.\n"; }();

    cout << "In main, there are " << numCats << " cats.\n";

    return 0;
}