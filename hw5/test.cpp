//calculator
#include"std_lib_facilities_4.h"
int main(){
ifstream ist{"in.txt"};
char operands;
vector<char>test;
while(ist>>operands)
{
    test.push_back(operands);
}
int n=test.size();
int i=0;
string drill;
if(test[n-1]=='+'||test[n-1]=='-'||test[n-1]=='*'||test[n-1]=='/')
drill="invalid";
else{
    while(true)
    {
        if(test[i]=='+'||test[i]=='-'||test[i]=='*'||test[i]=='/')
        break;
        i++;
    }
    int sum1=0;
    if(i!=0)
    {
        int a=0;
        while(a<i)
        { 
            int c=test[i-1-a]-'0';
            sum1=sum1+c*pow(10,a);
            a++;  
        }
    }
    int b=0;
    int sum2=0;
    while(b<n-i-1)
    {
            int c=test[n-b-1]-'0';
            sum2=sum2+c*pow(10,b);
            b++; 
    }
    int result;
    switch(test[i])
    {
        case '+':
        result=sum1+sum2;
        break;
        case '-':
        result=sum1-sum2;
        break;
        case '*':
        result=sum1*sum2;
        break;
        case '/':
        result=sum1/sum2;
        break;
    }
    drill=to_string(result);
}
cout<<drill<<endl;
}



   

