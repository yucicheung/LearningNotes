/*
回文串:反转以后和原串相同，如abba/madam
镜像串:镜像之后和原串相同，如2S和3AIAE

镜像翻转后值合法的有：AE(3)HIJ(L)L(J)MOS(2)TUVWXYZ(5)12(S)3(E)5(Z)8

输入：每行一个字符串(不包含空白字符)
输出：判断是否为回文串和镜像串，每组数据之后输出一个空行
*/
#include<string.h>
#include<stdio.h>
#include<ctype.h>

using namespace std;
char inStr[40];
const char mir[]="A   3  HIL JM O   2TUVWXY501SE Z  8 ";
char getMir(char ch)
{
    if(isalpha(ch))return mir[ch-'A'];
    return mir[ch-'0'+26];
}
char* msg[]={"not a palindrome","a regular palindrome","a mirrored string","a mirrored palindrome"};

int main()
{

    while(scanf("%s",inStr)==1)
    {
        int m=1,p = 1;
        int len = strlen(inStr);
        for(int i=0;i<(len/2);i++)
        {
            if(!(getMir(inStr[i])==inStr[len-1-i])) m=0;
            if(!(inStr[i]==inStr[len-1-i])) p=0;
        }
        printf("%s -- is a %s\n\n",inStr,msg[m*2+p]);
    }
    return 0;
}


