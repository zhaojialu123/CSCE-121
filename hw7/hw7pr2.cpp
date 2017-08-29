//Jialu Zhao
//CSCE 121-508 
//Due: December 7, 2016 
//hw7pr2.cpp 
#include <regex>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
try
{
	ifstream in{"file.txt"};//read file from file.txt
	if(!in) cerr<<"no file\n";
	regex pat{R"((\d{3})\-?(\d{2})\-?(\d{4}))"};//give the pattern
	int lineno=0;
  for(string line; getline(in,line);)
	{
		++lineno;
		smatch matches;
		   if (regex_search(line, matches, pat))
           {
           	//catch invalid UIN or security numbers
           	if(matches[0]=="042684425"||
           	matches[0]=="078051120"||
           	matches[0]=="123456789"||
           	matches[0]=="111111111"||
           	matches[0]=="222222222"||
           	matches[0]=="333333333"||
           	matches[0]=="444444444"||
           	matches[0]=="555555555"||
           	matches[0]=="666666666"||
           	matches[0]=="777777777"||
           	matches[0]=="888888888"||
           	matches[0]=="999999999"||
           	matches[0]=="987654320"||
           	matches[0]=="987654321"||
           	matches[0]=="987654322"||
           	matches[0]=="987654323"||
           	matches[0]=="987654324"||
           	matches[0]=="987654325"||
           	matches[0]=="987654326"||
           	matches[0]=="987654327"||
           	matches[0]=="987654328"||
           	matches[0]=="987654329")
           	cout<< lineno << ": " <<"An invalid UIN or invalid Security number!"<<'\n';//handle the invalid value
           	else
            {
              if (3<matches.size() && matches[1].matched&& matches[2].matched&& matches[3].matched) //handle the sub part                              
           {
            if(matches[2]=="00")
              cout<< lineno << ": " <<"A valid UIN!"<<'\n';
            else
            {
              if(matches[1]=="000"||matches[2]=="00"||matches[3]=="0000"||matches[1]=="666")
                cout<< lineno << ": " <<"An invalid UIN or invalid Security number!"<<'\n';
              else
              {
                if(stoi(matches[1])>=900&&stoi(matches[1])<=999)
                  cout<< lineno << ": " <<"An invalid UIN or invalid Security number!"<<'\n';
                else 
                  cout<< lineno << ": " <<"A valid Security number!"<<'\n';
              }
            }
           }        
        }
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
          

