//Jialu Zhao
//CSCE 121-508
//Due: September 15, 2016
//hw2pr2.cpp
#include"std_lib_facilities_4.h"
double my_cbrt_1(double n)
{
return -0.411665*n*n+1.03455*n+0.377113;
}
// definite function of my_cbrt_1
int main()
{
	try
	{	
		
		for(auto k : {-100, -10, -1, 0, 1, 10, 100})
			//loop through k, n is based on k to change
		{
			double n= M_PI * pow(10.0, k);
			cout<<n<<"	"<<cbrt(n)<<"	"<<my_cbrt_1(n)<<"\n";
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
