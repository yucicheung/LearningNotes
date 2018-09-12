#include<thread>
#include<iostream>
#include<mutex>
#include<atomic>
using namespace std;

mutex m;
const int N=1e6;
//int n;
atomic<int> n(0);

void increase_n()
{
    for(int i=0;i<N;i++)
    {
        //m.lock();
        ++n;
        //m.unlock();
    }
}

int main()
{
    thread t1(increase_n);
    thread t2(increase_n);

    t1.join();
    t2.join();

    cout<<n<<endl;
    return 0;
}
