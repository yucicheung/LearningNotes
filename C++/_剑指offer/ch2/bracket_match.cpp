/*
判断输入的符号串是否有效
*/
#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool func(const string& input)
{
    if(input.size()==0) return false;
    if(input[0]==')') return false;
    stack<char> leftStack;
    for(int i=0;i<input.size();i++)
    {
        if(input[i]==')')
        {
            if(leftStack.empty()) return false;
            else leftStack.pop();
        }
        else{
            leftStack.push(input[i]);
        }
    }
    if(leftStack.empty())return true;
    else return false;
}

int main()
{
    string input;
    while(cin>>input)
        cout<<func(input)<<endl;
    return 0;
}
