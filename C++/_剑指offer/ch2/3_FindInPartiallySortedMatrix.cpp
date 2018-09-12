#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rowCount = array.size();
        int colCount = array[0].size();
        int i=0,j=colCount-1;
        for(;i<=rowCount-1&&j>=0;)
        {
            if(target==array[i][j]) return true;
            else if(target<array[i][j]){--j;continue;}
            else {++i;continue;}
        }
        return false;
    }
};
