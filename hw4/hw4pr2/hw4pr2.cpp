//Jialu Zhao
//CSCE 121-508
//Due: October 4, 2016 
//hw4pr2.cpp
#include"std_lib_facilities_4.h"
#include"Chrono.h"
int main()
{
    try
    {
        Chrono::Date d;// using d in Chrono
        cout<<"Enter date as (yyyy,mm,dd):";
        cin>>d;
        cout<<"Enter number of days to add:";
        int n;
        cin>>n;
        if (n < 0) 
        {
            throw Chrono::Exception();//n should be positive
        }

        // using while loop to continously type date
        while(true){
        d.add_day(n);//using function add_day in d
        cout<<" That will be "<< d <<endl;
        cout<<"Enter date as (yyyy,mm,dd):";
		cin>>d;
        if(!cin){
			cout << "Not a vaild input"<< endl;
			break;
		}
        cout<<"Enter number of days to add:";
        cin>>n;
		if (n < 0) 
        {
            throw Chrono::Exception();//n should be positive
        }
        }
         return 0;
    }
catch (Chrono::Exception)//catch the exception which throw before
{
    cout<<"n should be positive";
}

   
    catch(exception&e)//exception handling
    {
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
       



