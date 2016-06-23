#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>

using namespace std;

int count = 0;
queue<int> data_queue;
mutex mut;
condition_variable data_cond;

void data_preparation_thread()
{
    while(true)
    {
        lock_guard<mutex> lk(mut);
        data_queue.push(count++);
        data_cond.notify_one();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void data_processing_thread()
{
    while(true)
    {
        unique_lock<mutex> lk(mut);
        data_cond.wait(lk, []{return !data_queue.empty();});
        int data = data_queue.front();
        data_queue.pop();
        lk.unlock();
        cout << data << " " ;

    }
}

int main()
{
    thread t1(data_preparation_thread), t2(data_processing_thread);
    t1.join();
    t2.join();
    return 0;
}
