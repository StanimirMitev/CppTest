/*  C++ Basics 5
    
    Explain what is the problem with the code below and how it should be avoided?
*/

#include <iostream>

using namespace std;

class Sample
{ 
public: 
    int *ptr;
    Sample(int i)
    { 
        ptr = new int(i);
    }
    Sample(const Sample& obj)
    {
        ptr = new int(*obj.ptr);
    }
    ~Sample()
    { 
        delete ptr;
    }
    void PrintVal()
    { 
        cout << "The value is " << *ptr;
    }
};

// in the original code we were apssing the object by value and the destructor was being called on function exit.
// Since we provided a destructor that frees up the memory, when we return to main our object's member is not pointing to alredy freed up memery.
// We can also provide a copy constructor to avoid showoll coping the object.
void SomeFunc(Sample& x)
{ 
    cout << "Say i am in someFunc " << endl;
}
int main()
{ 
    Sample s1(10);
    SomeFunc(s1);
    s1.PrintVal();
    return 0;
}
