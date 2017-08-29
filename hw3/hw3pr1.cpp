//Jialu Zhao
//CSCE 121-508
//Due: September 22, 2016
//hw3pr1.cpp
#include"std_lib_facilities_4.h"
int main()
{
    try{
			int amendment_number=0;
			cout<<"Which amendment?\n";//let users input numbers they want to the answers
			while(cin>>amendment_number)//using while loop to continuously ask for an input from the user
			{
				switch(amendment_number)//using switch and case to choose the answer matching to the number
				{
					case 1:
						cout<<"Amendment 1 guarantees freedom of religion, speech, press, assembly, and petition.\n";
						break;
					case 2:
						cout<<"Amendment 2 guarantees right to bear arms.\n";
						break;
					case 3:
						cout<<"Amendment 3 guarantees no quartering of troops.\n";
						break;
					case 4:
						cout<<"Amendment 4 guarantees no illegal search and seizure.\n";
						break;
					case 5:
						cout<<"Amendment 5 guarantees right to due process, grand jury, no double jeopardy, no self-incrimination, & eminent domain.\n";
						break;
					case 6:
						cout<<"Amendment 6 guarantees a speedy, public, impartial trial by jury.\n";
						break;
					case 7:
						cout<<"Amendment 7 guarantees right to a trial by jury in a civil case over $20.\n";
						break;
					case 8:
						cout<<"Amendment 8 guarantees no cruel and unusual punishment.\n";
						break;
					case 9:
						cout<<"Amendment 9 guarantees unenumerated rights not necessarily written out in the Constitution.\n";
						break;
					case 10:
						cout<<"Amendment 10 guarantees rigthts reserved to the states.\n";
						break;
					default:
						cout<<"That is not a vaild input. Please enter a number between 1 and 10.\n";
						break;
				}
			}
				return 0;
	    }   
    catch(exception&e){// catch exception
        cerr<<"error:"<<e.what()<<'\n';
        return 1;
    }
    catch(...){
        cerr<<"Oops:unknown exception!\n";
        return 2;
    }
}


