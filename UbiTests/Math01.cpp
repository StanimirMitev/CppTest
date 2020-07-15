/*  C++ Maths 1
    
    Given two 3D vectors (A, B) and a weight (W), construct a new 3D vector (C) which is a linear interpolation of the given two vectors.
*/

#include <iostream>
#include <random>

struct Vec3
{
    float x, y, z;
};

Vec3 LinearInterpolation(const Vec3& a, const Vec3& b, float w)
{
    Vec3 result = {0,0,0};
    return result;
}

void main(int argc, char* argv[])
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<float> random(-32.0f, 32.0f);

    Vec3  A = { random(rng), random(rng), random(rng) };
    Vec3  B = { random(rng), random(rng), random(rng) };
    float W = 0.85f;
    Vec3  C = LinearInterpolation(A, B, W);

    std::cout << C.x << ", " << C.y  << ", " << C.z << std::endl;
}