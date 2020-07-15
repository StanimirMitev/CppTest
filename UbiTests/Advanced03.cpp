/*  C++ Advanced 3
    
    The function 'f1' adds even numbers in a global vector.
    The function 'f2' adds odd numbers in a global vector.
    Fix the code below so the numbers are always added sequentially in ascending order.

    The class Semaphore could be used for inter thread synchronization.
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

class Semaphore {
public:
    Semaphore (int count_ = 0)
        : count(count_) {}

    inline void unlock()
    {
        std::unique_lock<std::mutex> lock(mtx);
        count++;
        cv.notify_one();
    }

    inline void lock()
    {
        std::unique_lock<std::mutex> lock(mtx);

        while(count == 0){
            cv.wait(lock);
        }
        count--;
    }

private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
};

static std::mutex gs_add_mutex;
static std::vector<int> g_vector;

void add_number(int number)
{
    std::lock_guard<std::mutex> guard(gs_add_mutex);
    g_vector.push_back(number);
}

void f1(int n)
{
    for (int i = 0; i < n; ++i)
    {
        if ((i % 2) == 0)
        {
            add_number(i);
        }
    }
}

void f2(int n)
{
    for (int i = 0; i < n; ++i)
    {
        if ((i % 2) != 0)
        {
            add_number(i);
        }
    }
}

void main(int argc, char* argv[])
{
    const int n = 100;

    std::cout << "--- BEGIN ---" << std::endl;

    std::thread t1(f1, n);
    std::thread t2(f2, n);

    t1.join();
    t2.join();

    for(int i = 0; i < n; ++i)
    {
        if(g_vector[i] != i)
        {
            std::cout << "Error for index[ " << i << "]. Current: " << g_vector[i] << " Should be: " << i << std::endl; 
        }

    }

    std::cout << "---  END  ---" << std::endl;
}