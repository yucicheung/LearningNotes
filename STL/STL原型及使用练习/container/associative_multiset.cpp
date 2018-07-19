#include<iostream>
#include<set>
#include<iterator>
#include<algorithm>
int main()
{
	const int N=10;
	int a[N]={4,1,1,1,1,1,0,5,1,0};
	int b[N]={4,4,2,4,2,4,0,1,5,5};

	std::multiset<int> multiSetA(a,a+N);
	std::multiset<int> multiSetB(b,b+N);
	std::multiset<int> multiSetC;	
	std::cout<<"Set A:";
	std::copy(multiSetA.begin(),multiSetA.end(),std::ostream_iterator<int>(std::cout," "));
	std::cout<<std::endl<<"Set B:";
	std::copy(multiSetB.begin(),multiSetB.end(),std::ostream_iterator<int>(std::cout," "));
	std::cout<<std::endl;

	std::cout<<"Union:";
	std::set_union(multiSetA.begin(),multiSetA.end(),multiSetB.begin(),multiSetB.end(),
				std::ostream_iterator<int>(std::cout," "));
	std::cout<<std::endl;

	std::cout<<"Intersection:";
	std::set_intersection(multiSetA.begin(),multiSetA.end(),multiSetB.begin(),multiSetB.end(),
				std::ostream_iterator<int>(std::cout," "));
	std::cout<<std::endl;

	std::cout<<"Set C: difference of A and B";
	std::set_difference(multiSetA.begin(),multiSetA.end(),multiSetB.begin(),multiSetB.end(),
				std::inserter(multiSetC,multiSetC.end()));
	std::copy(multiSetC.begin(),multiSetC.end(),std::ostream_iterator<int>(std::cout," "));

	return 0;
}
