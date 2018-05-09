#include<iostream>
using namespace std;
template <class type>//numtype
class Compare
{
public:
	Compare(type a,type b):x(a),y(b){};
	type max();
	type min();
private:
	type x,y;
};
template <class type>
type Compare<type>::max()
{
return (x>y?x:y);
}

template <class type>
type Compare<type>::min()
{
return (x<y?x:y);
}

int main()
{
Compare<int> compInt(1,2);
Compare<char> compChar('A','B');
Compare<float> compFloat(1.5,2.4);
cout<<compInt.max()<<','<<compInt.min()<<endl;
cout<<compChar.max()<<','<<compChar.min()<<endl;
cout<<compFloat.max()<<','<<compFloat.min()<<endl;
return 0;
}
