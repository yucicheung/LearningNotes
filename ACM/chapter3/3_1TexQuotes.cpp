/*
����һƪ����˫���ŵ�����
��Tex�е�"�ĳ������ź�������
*/

#include<string.h>
#include<stdio.h>

int main()
{
    char c,left=1;
    while((c=getchar())!=EOF)//��ֵ������ȼ�����!=
    {
        if(c=='"')
        {
            printf("%s",left?"��":"��");
            left=!left;
        }
        else printf("%c",c);
    }
    return 0;
}
