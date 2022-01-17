#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool match(string numString)
{
    return numString.size() == 3;
}

// Passing in a function pointer
// Good for when your function needs some repetitive code chunks
// I.E. for testing how fast each function runs (pass in an array of function pointers)
int countMatches(const vector<string> &numbers, bool (*funcPtr)(string))
{
    int matches = 0;
    for(int i = 0; i < numbers.size(); i++)
    {
        if(funcPtr(numbers[i])) matches++;
    }

    return matches;
}

int main()
{
    vector<string> numbers = {"one",
                              "two",
                              "three",
                              "four",
                              "five",
                              "six",
                              "seven"};


    cout << "Number of matches is " << countMatches(numbers, match) << endl;

    return 0;
}