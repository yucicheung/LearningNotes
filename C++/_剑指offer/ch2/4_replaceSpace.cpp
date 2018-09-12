#include<cstddef>
#include<string>
#include<iostream>

using namespace std;

//原地操作，不开辟新空间
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str==nullptr||length<=0) return;

        //找到空格总数和原字符串长度
        int spaceCount=0;
        int oldSize=0;
        while(str[oldSize] != '\0')
        {
            if(str[oldSize] == ' ') spaceCount++;
            ++oldSize;
        }
        cout<<spaceCount<<endl;

        // 对新字符串数组做填充
        int newSize = oldSize+2*spaceCount;
        if(newSize>length) return;
        // 注意，结束符'\0'也应该拷贝到数组中
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
