using namespace std;
class Time
{
};

int main()
{
Time t1,t2;
Time * const pt=&t1;
//pt=&t2;//illegal
return 0;
}
