#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

using namespace std;

template<typename Iterator, typename T>
struct accumulate_block
{
    void operator()(Iterator first, Iterator last, T& result)
    {
        result = accumulate(first, last, result);
    }
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
    unsigned long const length = distance(first, last) ;
    if(!length)
        return init;

    unsigned long const min_per_thread = 25;
    unsigned long const max_threads = (length + min_per_thread - 1) / min_per_thread;
    unsigned long const hardware_threads = thread::hardware_concurrency() ;
    unsigned long const num_threads = min(hardware_threads ? 2 : hardware_threads, max_threads) ;
    unsigned long const block_size = length / num_threads ;

    vector<T> resultsvec(num_threads);
    vector<thread> threads(num_threads - 1);

    Iterator block_start = first;
    for(unsigned long i=0;i<(num_threads-1);++i)
    {
        Iterator block_end = block_start;
        advance(block_end, block_size);
        threads[i] = thread(accumulate_block<Iterator, T>(), block_start, block_end, ref(resultsvec[i]));
        block_start = block_end;
    }

    accumulate_block<Iterator, T>()(block_start, last, resultsvec[num_threads - 1]);
    for_each(threads.begin(), threads.end(), mem_fn(&thread::join));

    return accumulate(resultsvec.begin(), resultsvec.end(), init);
}
/*
int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    vector<int> vec(a, a+20);
    int result = parallel_accumulate(vec.begin(), vec.end(), 0);
    cout << result << endl;
}
*/

