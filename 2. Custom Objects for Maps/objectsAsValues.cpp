#include <iostream>
#include <string>
#include <map>
#include "Person.hpp"

using namespace std;

int main()
{
    map<int, Person> personMap;

    personMap[0] = Person("John", 25);
    personMap[1] = Person("Christoph", 24);
    personMap[2] = Person("Nancy", 46);

    for(auto p : personMap)
    {
        p.second.print();
    }

    return 0;
}