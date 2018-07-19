#include<iostream>
#include<set>
#include<iterator>
#include<cassert>

int main()
{
	std::set<int> mySet;
	for (int i=1;i<5;i++)
	{
		mySet.insert(i*10);
	}
	std::pair<std::set<int>::iterator,bool> insertRes = mySet.insert(20);
	assert(insertRes.second==false);

	int myInts[] ={5,10,50};
	mySet.insert(myInts,myInts+3);

	std::copy(mySet.begin(),mySet.end(),std::ostream_iterator<int>(std::cout,"\n"));
	return 0;
}
