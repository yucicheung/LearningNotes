#include<iostream>
using namespace std;

struct Student
{int num;
float score;
struct Student* next;
};

int main()
{
Student a,b,c,*head=&a,*p=head;
a={31001,89.5,&b};
b={31003,90,&c};
c={31007,85,NULL};
while(p != NULL)
	{
	cout<<"num="<<(*p).num<<','<<"score="<<p->score<<endl;
	p = p->next;
	}
return 0;
}
