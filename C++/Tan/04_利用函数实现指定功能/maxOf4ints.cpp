#include<iostream>
using namespace std;
int max(int x,int y){return (x>y?x:y);}
int main()
{int a,b,c,d;
cout<<"Input 4 integars:";
cin>>a>>b>>c>>d;
cout<<max(max(max(a,b),c),d)<<endl;
return 0;
}

