#include <iostream>
#include <future>
#include <cstdio>
#include "parallel.h"
#include "threadsafe_stack.h"

using namespace std;

int answer1()
{
    cout << "answer1:" << this_thread::get_id() << endl;
    //printf("answer1: %d\n",this_thread::get_id());
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    vector<int> vec(a, a+20);
    int result = parallel_accumulate(vec.begin(), vec.end(), 0);
    return result;
}

int answer2()
{
    cout << "answer2:" << this_thread::get_id() << endl;
    //printf("answer2: %d\n",this_thread::get_id());
    int a[] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200};
    vector<int> vec(a, a+20);
    int result = parallel_accumulate(vec.begin(), vec.end(), 0);
    return result;
}

int main()
{
    /*
    future<int> the_answer = async(launch::deferred, answer1);
    int result = answer2();
    cout << "answer1: " << the_answer.get() << " answer2: " << result << endl;

    packaged_task<int()> myPackaged(answer1);//���ȴ���packaged_task����myPackaged���ڲ�����һ������task��һ������״̬(���ڷ���task�Ľ��)
    future<int> myFuture=myPackaged.get_future();//ͨ��packaged_task::get_future()����һ��future����myFuture���ڻ�ȡtask��������
    thread myThread(move(myPackaged));
    int result = answer2();
    //int result = 0;
    cout << "answer1: " << myFuture.get() << " answer2: " << result << endl;
    myThread.join();
*/
}

