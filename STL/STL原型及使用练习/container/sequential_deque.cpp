#include<iostream>
#include<deque>
#include<iterator>
#include<algorithm>

int main()
{
	std::deque<int> aDeque;
	aDeque.push_front(1);
	aDeque.push_back(3);
	aDeque.insert(aDeque.begin()+1,2);
	aDeque[0]=0;
	std::copy(aDeque.begin(),aDeque.end(),std::ostream_iterator<int>(std::cout,"\n"));
	return 0;
}
