//Jialu Zhao
//CSCE 121-508
//Due: September 22, 2016
//hw3pr2.cpp
#include"std_lib_facilities_4.h"
int main()
{
    try{
        vector<string>answers(11);// define a string vector containing all answers, answers[0] is void
		answers[1]=".Amendment 1 guarantees freedom of religion, speech, press, assembly, and petition.\n";
        answers[2]="Amendment 2 guarantees right to bear arms.\n";
        answers[3]="Amendment 3 guarantees no quartering of troops.\n";
        answers[4]="Amendment 4 guarantees no illegal search and seizure.";
        answers[5]="Amendment 5 guarantees right to due process, grand jury, no double jeopardy, no self-incrimination, & eminent domain.\n";
        answers[6]="Amendment 6 guarantees a speedy, public, impartial trial by jury.\n";
        answers[7]="Amendment 7 guarantees right to a trial by jury in a civil case over $20.\n";
        answers[8]="Amendment 8 guarantees no cruel and unusual punishment.\n";
        answers[9]="Amendment 9 guarantees unenumerated rights not necessarily written out in the Constitution.\n";
        answers[10]="Amendment 10 guarantees rigthts reserved to the states.\n";
		cout<<"Which amendment?\n";
        int amendment_number=0;
        while(cin>>amendment_number)
		{
			if(amendment_number<1||amendment_number>10)
				cout<<"That is not a vaild input. Please enter a number between 1 and 10.\n";// output error messages
			else
				cout<<answers[amendment_number]<<'\n';//using the amnedment_number to find matching answer from vector
        }
		return 0;
    }
    catch(exception&e){//catch exception
        cerr<<"error:"<<e.what()<<'\n';
        return 1;
    }
    catch(...){
        cerr<<"Oops:unknown exception!\n";
        return 2;
    }
}
