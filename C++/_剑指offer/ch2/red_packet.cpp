#include<iostream>
#include<cstdlib>
#include<tchar.h>
#include<locale>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  locale loc("chs");
  wcout.imbue(loc);
  wcout <<L"����1234"<< endl;
  int total,numOfPeople;
  float sumOfPacket,minOfPacket,maxOfPacket;
  wcin>>L"�ܽ��">>total>>L",Ԫ,������">>numOfPeople>>L",�����С���">>minOfPacket>>L"Ԫ,�����">>maxOfPacket>>L"Ԫ";

  int index = 0;
  float thisPacket=1,restOfPacket=sumOfPacket-thisPacket ;
  cout<<"��"<<index+1<<"���������ĺ�����Ϊ"<<thisPacket<<"Ԫ,���ʣ����Ϊ"<<restOfPacket<<endl;
  index++;
  while(index<total-1)
  {
    thisPacket=minOfPacket+rand()/(RAND_MAX)*(maxOfPacket-minOfPacket);
    restOfPacket-=thisPacket;
    cout<<"��"<<index+1<<"���������ĺ�����Ϊ"<<thisPacket<<"Ԫ,���ʣ����Ϊ"<<restOfPacket<<endl;
    index++;
  }
  thisPacket=restOfPacket;
  cout<<"��"<<index+1<<"���������ĺ�����Ϊ"<<thisPacket<<"Ԫ,���ʣ����Ϊ"<<restOfPacket<<endl;
  return 0;
}
