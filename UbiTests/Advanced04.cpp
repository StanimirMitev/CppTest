/*  C++ Advanced 4

    Examine the code below and make as many optimizations as you can.
*/

#include <iostream>

const double PI = 3.14159265;

inline double deg2rad(double deg)
{
    return deg * PI / 180;
}

inline double compute_value(double degrees)
{
    return tan(deg2rad(degrees));
}

void main(int argc, char* argv[])
{
    double degrees = 0;

    do
    {
        double val = compute_value(degrees);

        std::cout << degrees << ": " << val << std::endl;

        degrees += 1;
    } while (degrees <= 360);
}