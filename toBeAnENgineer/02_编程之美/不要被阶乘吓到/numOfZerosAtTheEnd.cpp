/*
����1������һ������N����ôN!��ĩβ�ж��ٸ�0�أ�
������
(1)N=K*10^M������K���ܱ�10����
(2)��һ����N=K*10^M=P*(2^X)*(5^Z)����Ϊx��ֵ����Զ����z��ֵ�����M=min(X,Z)=Z
(3)�ɴˣ�����ֻ��Ҫ��������5�ĸ���
*/
#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int input;
    cin>>input;

    //����һ
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

    //������
    ret = 0;
    while(input)
    {
        input /= 5;
        ret += input; //ֻ��5N(5�ı���)���ܸ�5�ĸ���������
    }
    cout<<ret<<endl;
    return 0;
}
