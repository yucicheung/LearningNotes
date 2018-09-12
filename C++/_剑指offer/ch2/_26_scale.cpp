#include <iostream>
#include <string>
using namespace std;

void func(float x){
    string str = "abcdefghijklmnopqrstuvwxyz";
    string strRet = "";
//判断正负数
    int flag = (x>=0);
    x = flag?x:-x;
//n为整数 m为小数部分
    long n = (long)x;
    int m = (x-n+0.005)*100;
    cout<<m<<endl;
//整数部分处理
    if(n==0) strRet=str[n];
    while(n){
        strRet = str[n%26]+strRet;
        n =n/26;
   }
//小数部分处理
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
