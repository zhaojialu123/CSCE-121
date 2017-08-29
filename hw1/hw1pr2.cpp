//Jialu Zhao
//CSCE 121-508
//Due: September 8, 2016 
//hw1pr2.cpp
#include"std_lib_facilities_4.h"
int main()
{
	double left,right,result;
	char operation;
	cout<<"write simple operation.\n";// prompt people to understand this is a simple calculator.
	while(cin >> left >> operation >> right) {//make people to enter number and operator.
		if(operation=='*')
			result=left*right;
		if(operation=='/')
			result=left/right;
		if(operation=='+')
			result=left+right;
		if(operation=='_')
			result=left-right;
		cout<<"result is "<<result<<"\n";
	}
		
	
	return 0;
}