/*  C++ Algorithms 1

    Consider the following sequence – 0,1,1,2,3,5,8,13,21,34,55,89,144...

    1. Write an iterative function to return the nth element of the sequence.
    2. Write a recursive function to return the nth element of the sequence.
*/

#include <iostream>

int sequence(unsigned n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    int num = 0;
    int fibA = 0;
    int fibB = 1;
    for (size_t i = 2; i < n; i++)
    {
        num = fibA + fibB;
        fibA = fibB;
        fibB = num;
    }
    return num;
}

int sequenceRecursive(unsigned n)
{
    if (n <= 1)
        return n;
    sequenceRecursive(n - 1) + sequenceRecursive(n - 2);
}

void main(int argc, char* argv[])
{
    std::cout << sequence(5) << std::endl;
    std::cout << sequence(5) << std::endl;
}

