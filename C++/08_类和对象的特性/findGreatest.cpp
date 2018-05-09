#include <iostream>
using namespace std;
class ArrayMax
{public:
	void inputArr();
	void findMax();
	void showMax();
private:
	int array[10];
	int max;
};

void ArrayMax::inputArr()
{
cout<<"Input 10 numbers:"<<endl;
int i;
for(i=0;i<=9;i++) cin>>*(array+i);
}

void ArrayMax::findMax()
{
int i;
max=array[0];
for(i=1;i<=9;i++) (max>*(array+i))?:max=*(array+i);
}

void ArrayMax::showMax()
{
cout<<"max="<<max<<endl;
}

int main()
{
ArrayMax arrmax;
arrmax.inputArr();
arrmax.findMax();
arrmax.showMax();
return 0;
}
