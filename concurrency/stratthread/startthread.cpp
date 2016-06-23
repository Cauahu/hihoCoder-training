#include <iostream>
#include <thread>
using namespace std;

class background_task
{
public :
    background_task()
    {
        cout << "background_task is start.\n";
    }
    background_task(const background_task& bt)
    {
        cout << "background_task is copying\n" ;
    }
    void operator()() const
    {
        cout << "background_task is running......\n" ;
    }

    ~background_task()
    {
        cout << "background_task is end.\n" ;
    }
};


class thread_guard
{
public :
    explicit thread_guard(thread& t_) : t(t_)
    {
        cout << "construct thread_guard.\n" ;
    }
    ~thread_guard()
    {
        cout << "destruct thread_guard.\n" ;
        if(t.joinable()){
            t.detach();
            //t.join();
        }
    }

    thread_guard(const thread_guard& ) = delete;
    thread_guard& operator = (const thread_guard& ) = delete;
private :
    thread& t;
};
/*

int main()
{
    background_task bt;
    thread t(bt);
    thread_guard tg(t);
    cout << "thread is running......\n" ;
    return 0;
}


t.datach():
background_task is start.
background_task is copying
background_task is copying
background_task is end.
background_task is running......
construct thread_guard.
background_task is end.
thread is running......
destruct thread_guard.
background_task is end.

t.join():
background_task is start.
background_task is copying
background_task is copying
background_task is end.
background_task is running......
background_task is end.
construct thread_guard.
thread is running......
destruct thread_guard.
background_task is end.


*/
