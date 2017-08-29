//Jialu Zhao
//CSCE 121-508
//Due: October 4, 2016 
//hw4pr4.cpp
#include"std_lib_facilities_4.h"
#include"Chrono.h"
int main()
{
    try
        {
            int y,m,q;// y means year, m means month, q means day
            Chrono::Date d;
            cout<<"Enter date (yyyy,mm,dd):";
            cin>>d;
			int temp=0;
            while(true){// using while loop to continously ype date
            d.day_of_week();//using the function in Chrono.cpp
            cout<<"Enter date (yyyy,mm,dd):";
            cin>>d;
			if(!cin){
			cout << "Not a vaild input"<< endl;
			break;
		}}
            return 0;
        }

    catch(exception&e){//exception handling
            cerr<<"error:"<<e.what()<<'\n';
            keep_window_open();
            return 1;	
            }
    catch(...){
            cerr<<"Oops:unknown exception!\n";
            keep_window_open();
            return 2;
}
}
       
