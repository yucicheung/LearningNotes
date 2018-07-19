#include<iostream>
#include<vector>
#include<string>

int main(int argc,char* argv[])
{
	std::vector<std::string> params;
	std::cout<<"Project name "<<argv[0]<<std::endl;
	
	for(int i=1;i<argc;i++)//range from 0 to argc-1
	{
		params.push_back(argv[i]);
		std::cout<<i-1<<std::endl;
		std::cout<<params[i-1]<<std::endl;
	}
	return 0;
}
