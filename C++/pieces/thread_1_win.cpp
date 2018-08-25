#include<windows.h>
#include<iostream>
using namespace std;
DWORD WINAPI Fun1Proc(LPVOID lpParameter)
{
    cout<<"Thread fucntion Func1Proc!\n";
    return 0;
}

int main()
{
    HANDLE hThread1 = CreateThread(NULL,0,Func1Proc,NULL,0,NULL);
    CloseHandle(hThread1);

    Sleep(1000);
    cout<<"main end!!\n";
    system("pause");
    return 0;
}
