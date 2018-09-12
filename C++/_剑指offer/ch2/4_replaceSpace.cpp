#include<cstddef>
#include<string>
#include<iostream>

using namespace std;

//ԭ�ز������������¿ռ�
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str==nullptr||length<=0) return;

        //�ҵ��ո�������ԭ�ַ�������
        int spaceCount=0;
        int oldSize=0;
        while(str[oldSize] != '\0')
        {
            if(str[oldSize] == ' ') spaceCount++;
            ++oldSize;
        }
        cout<<spaceCount<<endl;

        // �����ַ������������
        int newSize = oldSize+2*spaceCount;
        if(newSize>length) return;
        // ע�⣬������'\0'ҲӦ�ÿ�����������
        for(int oldIndex=oldSize,newIndex=newSize; oldIndex>=0 && newIndex>=0;--oldIndex)
        {
            if(str[oldIndex]==' ')
            {
                str[newIndex--] = '0';
                str[newIndex--] = '2';
                str[newIndex--] = '%';
            }
            else
            {
                str[newIndex--] =str[oldIndex];
            }
        }
	}
};

int main()
{
    char oldStr[30]{" We are happy."};
    Solution sol;
    sol.replaceSpace(oldStr,30);
    cout<<oldStr<<endl;
    return 0;
}
