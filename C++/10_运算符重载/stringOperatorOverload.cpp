#include<iostream>
#include<cstring>
using namespace std;

class String
{
public:
	String(){p=NULL;};
	String(char* str):p(str){};
	void display();
	bool operator > (String&);//for member func, data members from all objects are accessible
	bool operator < (String&);
	bool operator == (String&);
private:
	char *p;
};

void String::display()
{
cout<<p<<endl;
}

bool String::operator >(String& str)
{
if (strcmp(p,str.p)>0)
	return true;
else 
	return false;
}

bool String::operator <(String& str)
{
if (strcmp(p,str.p)<0) return true;
else return false;
}

bool String::operator ==(String& str)
{
if (strcmp(p,str.p)==0) return true;
else return false;
}

int main()
{
String str1("Hello"),str2("World");
cout<<"str1 ",str1.display();
cout<<"str2 ",str2.display();
cout<<"str1>str2 ?"<<(str1>str2?"True":"False")<<endl;
//cout<<("Hello">"World")<<endl;
cout<<"str1<str2 ?"<<(str1<str2?"True":"False")<<endl;
cout<<"str1==str2 ?"<<(str1==str2?"True":"False")<<endl;
return 0;
}
