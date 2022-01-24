#include <iostream>
#include "RingBuffer.hpp" // will add Initializer List Compatability

using namespace std;

int main()
{
    RingBuffer<string> names{"John", "Nancy", "Christoph"}; // init list

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