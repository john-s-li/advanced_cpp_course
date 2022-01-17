#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Struct padding (structs are padded for efficiency sake)
// When writing to binary files, need to remove this padding
// This is done via the pragma syntax
#pragma pack(push,1)
struct Person
{
    char name[50];
    int age;
    double weight;
};
#pragma pack(pop)

int main()
{
    Person someone  = {"Jim", 26, 150.5};
    string fileName = "test.bin";

    ofstream outFile;
    ifstream inFile;

    // Writing binary file
    cout << "Writing to binary file " << fileName << endl;
    outFile.open(fileName, ios::binary);
    if(outFile.is_open())
    {
        // When writing binary, ofstream expects a char pointer and the size of 
        // the data that is being written
        outFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));
        outFile.close();
    }
    else
    {
        cout << "Cannot write to " << fileName << endl;
        return 1;
    }
    cout << "Finished writing to binary file " << fileName << endl;

    // Reading binary file
    cout << "Reading from file " << fileName << endl;
    Person someoneElse = {}; // init zero struct
    inFile.open(fileName, ios::binary);

    if(inFile.is_open())
    {
        inFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));
        inFile.close();
    }
    else
    {
        cout << "Cannot read from " << fileName << endl;
        return 1;
    }
    cout << "Finsihed reading from file " << fileName << endl;

    cout << "Obtained binary data:\n " << "\tName: " << someoneElse.name << endl
    << "\tAge: " << someoneElse.age << endl << "\tWeight: " << someoneElse.weight << endl;

    return 0;
}