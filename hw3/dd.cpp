#include"std_lib_facilities_4.h"
int main()
{
    vector<int>numbers;
    int num;
    while(cin>>num)
    {
        numbers.push_back(cin);
        if(cin==';')
            break;
    }
    int sum=0;
    int i=numbers.size();
    while(i>=0)
    {
        sum=sum+numbers[i]*pow(10,numbers.size()-i);
        i=i-1;
    }
    cout<<sum<<"has";
}
