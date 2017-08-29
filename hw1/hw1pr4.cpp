
//Jialu Zhao
//CSCE 121-508
//Due: September 8, 2016 
//hw1pr4.cpp
#include"std_lib_facilities_4.h"
int main()
{
	int i=0;//make a vaiable to count number.
	auto x = 1;
	while(i<11){
		auto x2 = x*x;
		auto y = sqrt(x2);
		cout<<"square root of ("<<x<<" squared) is"<< y<<"\n";
		x*=10;
		i++;
	}
	cout << "This program produced some strange values since the square of x is larger than the boundary of integer,and the value will be not good and strange then the sqrt of strange value will be strange too. ";
}

