/*  C++ Basics 10
    
    Fix the problems with the class in the use case below.
*/

#include <iostream>
#include <random>

class FunArray
{
public:
    FunArray() : m_IsGenerated(false) {}
    ~FunArray() { delete[] m_Data; }

    void GenerateData(int dataSize)
    {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<char> randData(1, 100);

        m_DataSize = dataSize;
        for (unsigned i = 0; i < m_DataSize; ++i)
            ((char *)m_Data)[i] = randData(rng);
    }

    void Fun()
    {
        for (unsigned i=0; i < m_DataSize; ++i)
        {
            std::cout << ((char*)m_Data)[i] << std::endl;
        }
    }
private:
    void* m_Data;
    unsigned m_DataSize;
    bool m_IsGenerated;
};

void main(int argc, char* argv[])
{
    FunArray a;
    a.GenerateData(42);
    a.Fun();

    FunArray* b = new FunArray(a);
    b->Fun();
    delete b;
}

