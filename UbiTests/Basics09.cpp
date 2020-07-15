/*  C++ Basics 9
    
    The next questions are for multi thread environment:

    We have a thread Push which adds and element to a global vector.
    We have a thread Pop which removes element from a global vector.

    The two threads are working simultaneously.

    In the code below, what need to be done in order to have a synchronized access to the global vector?
*/

#include <vector>
#include <thread>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

vector<int> vec;

void push()
{
    for (int i = 0; i != 10; ++i)
    {
        cout << "Push " << i << endl;
        _sleep(500);
        // std vector is not tread safe, have to lock the resource while it is being read/written to
        mtx.lock();
        vec.push_back(i);
        mtx.unlock();
    }
}
void pop()
{
    for (int i = 0; i != 10; ++i)
    {
        if (vec.size() > 0)
        {
            mtx.lock();
            int val = vec.back();
            vec.pop_back();
            mtx.unlock();
            cout << "Pop "<< val << endl;
        }
        _sleep(500);
    }
}
int main()
{
    //create two threads
    std::thread push(push);
    std::thread pop(pop);
    if (push.joinable())
        push.join();
    if (pop.joinable())
        pop.join();

    return 0;
}

