//ѡ������
//ÿ�α�������һ����Сֵ����ӵ�һ����������
//�Ӷ��γ�һ���������е�����
//�����ð������ѡ������Ľ������������Щ
#include<vector>
#include<iostream>

using namespace std;

void selection_sort(vector<int>& input)
{
    if(input.size()==0||input.size()==1) return;
    for(size_t i =0;i<(input.size()-1);i++)
    {
        int min_index = i;
        for(size_t j = i+1;j<input.size();j++)
        {
            if(input[min_index]>input[j])
            {
                min_index = j;
            }
        }
        int tmp = input[i];
        input[i] = input[min_index];
        input[min_index] = tmp;
    }
    return;
}

int main()
{
    vector<int> input{8,9,4,5};
    selection_sort(input);
    for(auto i:input)
        cout<<i<<endl;
    return 0;
}
