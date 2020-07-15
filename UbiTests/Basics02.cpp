/*  C++ Basic 2
    
    Fix the problem with the code below. Write a comment explaining the cause.
*/

#include <iostream>

struct A
{
    A() { initData(); }

    virtual void initData() { m_data = 5; }
    virtual void processData() { m_data += 5; }

    int m_data;
};

struct B: public A
{  
    // As we did not provide a contructor for B, the profided contructor for A was being executed and a default constructor for B was beign created.
    B() { initData(); }
    virtual void initData() { m_data = 6; }
    virtual void processData() { m_data += 4; }
};

void main(int argc, char* argv[])
{
    A a;
    B b;
    a.processData();
    b.processData();
    std::cout << a.m_data << std::endl;
    std::cout << b.m_data << std::endl;
}
