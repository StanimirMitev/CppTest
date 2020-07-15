/*  C++ Basic 4

    Explain the result of running the program. Explain how its execution will end.
*/

#include <iostream>

void main(int argc, char* argv[])
{
    int c = 0;
    // all the expression are being evalated, but only the right most one is being kep.
    // "c<5" is being discarded resulting in a infinite loop
    while (c < 5, ++c)
        std::cout << c << std::endl;
}

