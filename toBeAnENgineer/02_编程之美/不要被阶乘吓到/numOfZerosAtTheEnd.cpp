/*
问题1：给定一个整数N，那么N!的末尾有多少个0呢？
分析：
(1)N=K*10^M，其中K不能被10整除
(2)进一步，N=K*10^M=P*(2^X)*(5^Z)，因为x的值可能远大于z的值，因此M=min(X,Z)=Z
(3)由此，我们只需要求含质因数5的个数
*/
#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int input;
    cin>>input;

    //方法一
    int ret=0;
    for(int i=1;i<=input;i++)
    {
        int j = i;
        while(j%5 == 0)
        {
            j /= 5;
            ++ret;
        }
    }
    cout<<ret<<endl;

    //方法二
    ret = 0;
    while(input)
    {
        input /= 5;
        ret += input; //只有5N(5的倍数)才能给5的个数做贡献
    }
    cout<<ret<<endl;
    return 0;
}
