//Jialu Zhao
//CSCE 121-508
//Due: September 15, 2016
//hw2pr1.cpp
#include"std_lib_facilities_4.h"
int main()
{
	try{
	    double income;
        cout<<" Income in dollars?\n";
        cin>>income;
        cout<<setprecision(2)<<fixed <<"you should give away about $"<<income/10.00<<","<<" save about $"<<income/10.00<<" ,"<<"and live on about $ "<<income/10.00*8.00<<".\n";
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
