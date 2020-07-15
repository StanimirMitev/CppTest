/*  C++ Maths 3

    A triangle is defined by three points:

    A(x1, y1, z1)
    B(x2, y2, z2)
    C(x3, y3, z3)

    Write a function that will return a vector perpendicular to the plane spawned by A, B and C.
*/

#include <iostream>
#include <random>

struct Vec3
{
    float x, y, z;
};

Vec3 CrossProduct(const Vec3 v1, const Vec3 v2)
{
    return Vec3{ v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x };
}

Vec3 GetVectorPerpendicularToPlane(const Vec3& a, const Vec3& b, const Vec3& c)
{
    Vec3 ab = { a.x - b.x ,a.y - b.y,a.z - b.z };
    Vec3 ac = { a.x - c.x ,a.y - c.y,a.z - c.z };

    return CrossProduct(ab, ac);
}

int main(int argc, char* argv[])
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<float> random(-32.0f, 32.0f);

    Vec3 A = { random(rng), random(rng), random(rng) };
    Vec3 B = { random(rng), random(rng), random(rng) };
    Vec3 C = { random(rng), random(rng), random(rng) };

    Vec3 result = GetVectorPerpendicularToPlane(A, B, C);

    std::cout << result.x << ", " << result.y << ", " << result.z << std::endl;
}