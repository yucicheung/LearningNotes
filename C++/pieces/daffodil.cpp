/*���100-999�����е�ˮ�ɻ���*/
#include<stdio.h>

int main()
{
    for(int a=1;a<=9;a++)
    {
        for(int b=0;b<=9;b++)
        {
            for(int c=0;c<=9;c++)
            {
                if((c*c*c+b*b*b+a*a*a)==(c+b*10+a*100))
                    printf("%d%d%d\n",a,b,c);
            }
        }
    }
    return 0;
}
