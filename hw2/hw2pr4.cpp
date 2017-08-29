//Jialu Zhao
//CSCE 121-508
//Due: September 15, 2016
//hw2pr3.cpp
#include"std_lib_facilities_4.h"
#include<iomanip>
#include<iostream>
#include<math.h>
using namespace std;
double my_cbrt_1(double n)
{
	return -0.411665*n*n+1.03455*n+0.377113;
}
double my_cbrt_2(double n)
//definate the function of my_cbrt_2
{
	double result=1;//set result to 1
	if(n>1)
		while(n>1)
		{
			result=result*2;
			n=n/8;
		}
	if(n<1/8)
		while(1/8)
		{	result=result/2;
			n=n*8;
		}
	return result*my_cbrt_1(n);
}
int main(){
try
{	
	int w = 20;//set the width
	cout<<setw(w)<<"n"<<setw(w)<<"cbrt(n)"<<setw(w)<<"my_cbrt_2(n)"<<setw(w)<<"relative_error_of_my_cbrt_2"<<endl;
	cout<<"========================================================================================================="<<endl;
	//output the column headings
	//use setw() with a arg for the width
	for(auto k : {-100, -10, -1, 0, 1, 10, 100})
	//loop through
	{
		double n = M_PI * pow(10.0, k);
		double relative_error_of_my_cbrt_2= 100 * ((my_cbrt_2(n))-(cbrt(n)))/cbrt(n);
		cout<<setw(w)<<n<<setw(w)<<cbrt(n)<<setw(w)<<my_cbrt_2(n)<<setw(w)<<relative_error_of_my_cbrt_2<<endl;
		//output n,cbrt(n),my_cbrt_2(n),and relative_error_of_my_cbrt_2.
	}
	return 0;
}
catch(exception&e){
		cerr<<"error:"<<e.what()<<'\n';
		keep_window_open();
		return 1;	
		}
	catch(...){
		cerr<<"Oops:unknown exception!\n";
		keep_window_open();
		return 2;
	}// exception handling
}