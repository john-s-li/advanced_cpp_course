#include <iostream>
#include <string>
#include <map>
#include "Person.hpp"

using namespace std;

int main()
{
    // maps sort keys using < operator
    // not straight forward for objects
    map<Person, int> personMap;

    personMap[Person("John", 25)] = 25;
    personMap[Person("Christoph", 24)] = 24;
    personMap[Person("Nancy", 46)] = 46;

    for(auto p : personMap)
    {
        p.first.print();
    }

    return 0;
}