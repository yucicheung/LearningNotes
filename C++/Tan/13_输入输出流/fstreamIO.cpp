#include<fstream>
#include<iostream>

using namespace std;

int main()
{
void saveLetterToFile(string filename);
string filename="f2.dat";
saveLetterToFile(filename);
void convertInFile(string,string);
string outFilename="f3.dat";
convertInFile(filename,outFilename);
void displayOnScreen(string);
displayOnScreen(filename);
displayOnScreen(outFilename);
return 0;
}

void saveLetterToFile(string filename)
{
ofstream file(filename);
if (!file)
	{
	cerr<<"open "<<filename<<" error!"<<endl;
	exit(1);
	}
char c[80];
cout<<"Please start to input:";
cin.getline(c,80);
int i =0;
while(c[i])
	{
	if ((c[i]>='A'&&c[i]<='Z')||(c[i]>='a'&&c[i]<='z')) file.put(c[i]);//file<<c[i];
	i++;
	}
file<<endl;
file.close();
}

void convertInFile(string inFilename,string outFilename)
{
ifstream infile(inFilename);
ofstream outfile(outFilename);
if(!infile)
	{
	cerr<<"open "<<inFilename<<" error!"<<endl;
	exit(1);
	}
if(!outfile)
	{
	cerr<<"open "<<outFilename<<" error!"<<endl;
	abort();
	}
char ch;
while(infile.get(ch))
	{
	outfile.put(ch&223);//convert from lower class to upper class
	}
infile.close();
outfile.close();
}

void displayOnScreen(string filename)
{
fstream file(filename);
if (!file)
	{cerr<<"open "<<filename<<" error!";
	exit(1);}
char ch;
while(file.get(ch))
	{
	cout<<ch;
	}
file.close();
}
