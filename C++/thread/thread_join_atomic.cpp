#include<thread>
#include<iostream>
#include<chrono>
#include<atomic>

std::atomic<int> id(1);

void f1()
{
    for(int i=0;i<=9;i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout<<"Thread "<<id.load()<<": f1 executing"<<std::endl;
    }
}
void f2()
{
    for(int i=0;i<=9;i++)
    {
        //id.store(i);
        ++id;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main()
{

    std::thread t2(f2);
    std::thread t1(f1);
    t1.join();
    std::cout<<t1.joinable()<<std::endl;    //t1»áºÏÍê±Ï
    t2.join();

    std::cout<<"Joined two threads"<<std::endl;
    return 0;
}
