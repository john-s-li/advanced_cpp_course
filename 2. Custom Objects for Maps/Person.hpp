#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
    public:
        Person(): _name(""), _age(0)
        {}

        Person(string name, int age)
        {
            _name = name;
            _age  = age;
        }

        Person(const Person &other) // copy constructor
        {
            _name = other._name;
            _age  = other._age;
        }

        void print() const
        {
            cout << "Name: " << _name << " and Age: " << _age << endl; 
        }

        // need this for using object as key or to be added to a set
        bool operator<(const Person &other) const
        {
            return _age < other._age;
        }

    private:
        string _name;
        int _age;

};

#endif
