//Jialu Zhao
//CSCE 121-508
//Due: October 4, 2016
//hw4pr1.cpp
#include"std_lib_facilities_4.h"
#include"Chrono.h"
int main()
{
try{
    int year;
    bool q = true;//define boolean q to make the while loop stop
    cout<<"Enter year (0 to quit):";
    cin>>year;
    while(true && q){
    bool isLeapYear = Chrono::leapyear(year);// use the function isleapyear in Chrono.cpp
    if (isLeapYear)
        cout<<year<<" is a leap year.\n";
    else
        cout<<year<<" is not a leap year.\n";
    cout<<"Enter year (0 to quit):";
    cin>>year;
    if(year==0)//use q to exit the loop
    {
        q = false;
    }
    }
    return 0;
}//exception handling
catch(exception&e){
		cerr<<"error:"<<e.what()<<'\n';
		keep_window_open();
		return 1;	
		}
catch(...)
{
		cerr<<"Oops:unknown exception!\n";
		keep_window_open();
		return 2;
}
}

