#include<stdio.h>
#include<string.h>

class CMyString
{
public:
    CMyString(char* pData_=NULL);
    CMyString(const CMyString&);
    ~CMyString(void);
    CMyString& operator=(const CMyString&);
private:
    char* pData_;
};

CMyString& operator=(const CMyString& str)
{
    if(&str==this)
        return *this;
    delete[] pData_;
    pData_ = NULL;
    pData_ = new char[strlen(str.pData_)+1];//+1是为了存储最终的结束符？还是为了存储数组长度
    strcpy(pData_,str.pData_);

    return *this;
}

int main()
{
    CMyString c();
    return 0;
}
