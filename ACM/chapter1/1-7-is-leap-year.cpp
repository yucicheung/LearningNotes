#include<stdio.h>

int main()
{
    int y;
    scanf("%d",&y);
    if(y%4==0)
    {
     if(y%400==0)
        printf("yes\n");
     else
        printf("no\n");
    }
    else
        printf("no");
    return 0;
}
