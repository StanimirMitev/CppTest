/*  C++ Maths 2

    Write a function WithinMaxAngle that checks if the angle between two arbitrary vectors is less than MAX_DEGREES.
*/

#include <iostream>

const float PI = 3.141593;

struct Vec3
{
    float x, y, z;
};

inline float VectorDotProduct(const Vec3& rhs, const Vec3& lhs)
{
    return rhs.x * lhs.x + rhs.y * lhs.y + rhs.z * lhs.z;
}

inline float VectorLength(const Vec3& other)
{
    return sqrt(other.x * other.x + other.y * other.y + other.z * other.z);
}

const float MAX_DEGREES = 43.f;

float CaculateAngleInDegrees(const Vec3& v1, const Vec3& v2)
{
    return acos(VectorDotProduct(v1, v2) / (VectorLength(v1) * VectorLength(v1))) * PI / 180;
}

bool WithinMaxAngle(const Vec3& v1, const Vec3& v2)
{
    if (CaculateAngleInDegrees(v1, v2) <= MAX_DEGREES)
        return true;
    return false;
}

void main(int argc, char* argv[])
{
    Vec3 a = { 1, 1, 1 };
    Vec3 b = { 0.3f, 0, 1 };
    Vec3 c = { 0.5f, 0, 1 };
    std::cout << WithinMaxAngle(a, b) << std::endl;
    std::cout << WithinMaxAngle(a, c) << std::endl;
}