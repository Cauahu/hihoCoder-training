#include <queue>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class threadsafe_queue
{
private:
    mutable mutex m;
    queue<T> data_queue;
    condition_variable data_cond;
public:
    threadsafe_queue(){}
    void push(T new_value)
    {
        lock_guard<mutex> lk(m);
        data_queue.push(move(new_value));
        data_cond.notify_one();
    }

    void wait_and_pop(T& value)
    {
        unique_lock<mutex> lk(m);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = move(data_queue.front());
        data_queue.pop();
    }
};
