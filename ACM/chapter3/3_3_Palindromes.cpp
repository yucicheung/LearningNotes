/*
���Ĵ�:��ת�Ժ��ԭ����ͬ����abba/madam
����:����֮���ԭ����ͬ����2S��3AIAE

����ת��ֵ�Ϸ����У�AE(3)HIJ(L)L(J)MOS(2)TUVWXYZ(5)12(S)3(E)5(Z)8

���룺ÿ��һ���ַ���(�������հ��ַ�)
������ж��Ƿ�Ϊ���Ĵ��;��񴮣�ÿ������֮�����һ������
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


