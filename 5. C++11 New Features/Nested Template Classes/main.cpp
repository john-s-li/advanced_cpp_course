#include <iostream>
#include "RingBuffer.hpp"

using namespace std;

int main()
{
    RingBuffer<string> names(3);

    names.add("John");
    names.add("Nancy");
    names.add("Christoph");

    for(RingBuffer<string>::Iterator it=names.begin(); it != names.end(); it++)
    {
        cout << *it << endl;
    }

    cout << "Adding a new name. . ." << endl;
    names.add("Simone");

    for(auto name: names)
    {
        cout << name << endl;
    }


    return 0;
}