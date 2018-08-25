/*
输入一篇包含双引号的文章
将Tex中的"改成左引号和右引号
*/

#include<string.h>
#include<stdio.h>

int main()
{
    char c,left=1;
    while((c=getchar())!=EOF)//赋值语句优先级低于!=
    {
        if(c=='"')
        {
            printf("%s",left?"“":"”");
            left=!left;
        }
        else printf("%c",c);
    }
    return 0;
}
