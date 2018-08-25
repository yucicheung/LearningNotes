#include<stdio.h>
#include<iostream>

int main()
{
    long long n,count =0;
    std::cin>>n;
    while(n>1)
    {
        if(n%2) n=3*n+1;
        else n = n/2;
        std::cout<<n<<std::endl;
        count++;
    }
    std::cout<<count<<std::endl;
    return 0;
}
