/*  C++ Basics 7

    Rewrite the implementation of the class Flags so it is more efficient in terms of memory and performance for the given value of MAX_FLAGS.
    Document any limitations this imposes on other possible MAX_FLAGS values.
*/

#include <iostream>
#include <random>
#include <bitset>

class Flags
{
public:
    static const int MAX_FLAGS = 4;

    Flags() {}

    bool getFlag(int i) { return m_flags[i]; }
    void setFlag(int i, bool v) { m_flags[i] = v; }
private:
    // we can replace the user of a raw array with a bitset. This would allow us to use 8 times less memory.
    // bitset's default construcor alrady sets every bit to 0, meaning we do not need to itterate over an array to set individual values.
    std::bitset<MAX_FLAGS> m_flags;
};


void main(int argc, char* argv[])
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> randIndex(0, Flags::MAX_FLAGS - 1);

    Flags flags;
    flags.setFlag(randIndex(rng), true);
    flags.setFlag(randIndex(rng), true);

    for (int i = 0; i < Flags::MAX_FLAGS; ++i)
    {
        std::cout << i << "->" << flags.getFlag(i) << std::endl;
    }
}

