#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// https://docs.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-unique-ptr-instances?view=msvc-170

class Test
{
    public:
        Test() : _occupation(make_unique<string>("None")) // initialized with init list
        {}
        Test(int id, string name, string occupation = "None") : 
            _id(id), _name(name), _occupation(make_unique<string>(occupation)) 
        {};
        Test(const Test& other) = default;
        Test& operator=(const Test& other)
        {
            _id = other._id;
            _name = other._name;
            *(_occupation) = other.getOccupation();
            return *this;
        }

        int getID() const { return _id; }
        string getName() const { return _name; }
        string getOccupation() const { return *(_occupation); } 

    private:
        int _id{0};
        string _name{"None"};
        unique_ptr<string> _occupation; // cannot intialize inline

};

unique_ptr<Test> TestFactory(const int id, const string &name)
{
    return make_unique<Test>(id, name); // Alternative to declaring from scratch
}


int main()
{   
    // 1. Declaring a unique ptr
    cout << "Declaring a Unique Ptr#############################\n";
    unique_ptr<Test> testPtr1(new Test(1,"John"));
    cout << "Name = " << testPtr1->getName() << endl; 

    // 2. Unique ptr being passed by function
    cout << "Passing Unique Ptr with functions##################\n";
    auto testPtr2 = TestFactory(2, "Chris"); 
    cout << "Name = " << testPtr2->getName() << endl; 
    // Move the unique ptr to another
    auto testPtr3 = move(testPtr2);
    // cout << "Name = " << testPtr->getName() << endl; // testPtr now deleted
    cout << "Name = " << testPtr3->getName() << endl; 

    // 3. Unique ptrs being used in a vector
    cout << "Unique Ptrs with vector ###########################\n";
    vector<unique_ptr<Test>> testVector;
    //testVector.push_back(testPtr1);
    //testVector.push_back(testPtr3);
    // ^ vectors will make copies to push them into it BUT for unique_ptrs, they cannot
    // be copied, so they can only be added to vectors upon instantiation
    testVector.push_back(TestFactory(3, "Flo"));
    testVector.push_back(TestFactory(4, "Chi"));

    for(const auto &ptr: testVector)
    {
         cout << "Name = " << ptr->getName() << endl; 
    }

    // 4. Unique ptr class member
    cout << "Unique ptrs with classes ##########################\n";
    Test t(1, "John", "Robotics Engineer");
    cout << t.getOccupation() << endl;

    // 5. Unique ptr to an array and array initialization
    cout << "Unique ptrs with arrays ###########################\n";
    auto arrayPtr = make_unique<int[]>(5);
    for (int i = 0; i < 5; i++)
    {
        arrayPtr[i] = i;
        cout << arrayPtr[i] << endl;
    }
    
    return 0;
}