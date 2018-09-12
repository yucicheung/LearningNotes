#include<iostream>
#include<cstdlib>
#include<tchar.h>
#include<locale>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  locale loc("chs");
  wcout.imbue(loc);
  wcout <<L"测试1234"<< endl;
  int total,numOfPeople;
  float sumOfPacket,minOfPacket,maxOfPacket;
  wcin>>L"总金额">>total>>L",元,总人数">>numOfPeople>>L",红包最小金额">>minOfPacket>>L"元,最大金额">>maxOfPacket>>L"元";

  int index = 0;
  float thisPacket=1,restOfPacket=sumOfPacket-thisPacket ;
  cout<<"第"<<index+1<<"个人抢到的红包金额为"<<thisPacket<<"元,红包剩余金额为"<<restOfPacket<<endl;
  index++;
  while(index<total-1)
  {
    thisPacket=minOfPacket+rand()/(RAND_MAX)*(maxOfPacket-minOfPacket);
    restOfPacket-=thisPacket;
    cout<<"第"<<index+1<<"个人抢到的红包金额为"<<thisPacket<<"元,红包剩余金额为"<<restOfPacket<<endl;
    index++;
  }
  thisPacket=restOfPacket;
  cout<<"第"<<index+1<<"个人抢到的红包金额为"<<thisPacket<<"元,红包剩余金额为"<<restOfPacket<<endl;
  return 0;
}
