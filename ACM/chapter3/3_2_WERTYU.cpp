/*
����Ϊ���Ҵ�λ���ó����ַ���(�����в�����ִ�д��ĸA)
*/
#include<stdio.h>
//#include<string.h>
#include<string>

std::string s="1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";//
int main()
{
    //printf("%s\n",s);
    char c;
    while((c=getchar())!=EOF)
    {
        int i = s.find(c);
        printf("%c",s[i-1]);
    }
    return 0;
}
