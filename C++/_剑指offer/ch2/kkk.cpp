#include <iostream>
#include <string>
using namespace std;

void func(float x){
    string str = "abcdefghijklmnopqrstuvwxyz";
    string strRet = "";
//�ж�������
    int flag = (x>=0);
    x = flag?x:-x;
//nΪ���� mΪС������
    long n = (long)x;
    int m = (x-n+0.005)*100;
    cout<<m<<endl;
//�������ִ���
    if(n==0) strRet=str[n];
    while(n){
        strRet = str[n%26]+strRet;
        n =n/26;
   }
//С�����ִ���
    string str2 = "";
    if(m>0){
        while(m){
            str2 =str2+str[m%26];
            m =m/26;
        }
        strRet = strRet + "." + str2;
    }
    strRet = (flag?"":"-") + strRet;
    cout << strRet << endl;
}
int main()
{
    float in;
    while(cin>>in)
    {
        func(in);
    }
    return 0;
}
