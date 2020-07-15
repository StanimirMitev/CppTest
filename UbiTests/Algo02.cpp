/*  C++ Algorithms 2

    Write a function that removes K random elements from a std::vector.
    The function should work in place, but does not need to preserve the order of elements.
*/

#include <iostream>
#include <vector>
#include <random>

void removeK(std::vector<int>& v, unsigned k)
{
    if (k >= v.size())
    {
        v.clear();
        return;
    }
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> randData(0, k);
    for (size_t i = 0; i < k; i++)
    {
        v.erase(v.begin() + randData(rng));
    }
}

void main(int argc, char* argv[])
{
    std::vector<int> arr;
    for (int i = 0; i < 50; ++i)
        arr.push_back(i);

    removeK(arr, 5);

    for (auto i : arr)
        std::cout << i << std::endl;
}
