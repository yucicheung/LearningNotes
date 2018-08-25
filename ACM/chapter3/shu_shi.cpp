/* 给定一个数字集合,属于1-9
找到所有的abc*de
使计算竖式中的所有值都属于给定的数字集合
*/

#include<stdio.h>
#include<string.h>
#define maxn 99

char buf[maxn];
char s[maxn];

int main()
{
    int counti=0;
    scanf("%s",s);
    for(int abc=111;abc<=999;abc++)
    {
        for(int de=11;de<=99;de++)
        {
            int x=abc*(de%10),y=abc*(de/10),z=abc*de;
            sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);
            int ok=1;
            for(int i=0;i<strlen(buf);i++)
            {
                if(strchr(s,buf[i])==NULL){ok=0;break;}
            }
            if(ok)
            {
                counti++;
                printf("<%d>\n",counti);
                if(z<10000)printf("%4d\nX%3d\n----\n%4d\n%d\n----\n%d\n\n",abc,de,x,y,z);
                else printf("%5d\nX%4d\n-----\n%5d\n%d\n-----\n%d\n\n",abc,de,x,y,z);
            }
        }
    }
    printf("The number of solutions = %d\n",counti);
    return 0;
}
