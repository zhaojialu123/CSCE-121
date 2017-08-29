//Jialu Zhao
//CSCE 121-508 
//Due: December 7, 2016 
//hw7pr1.cpp 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main()
try
{
 ifstream ist {"in.txt"};//read file from in.txt
 while(!ist.eof())//repeat until the end of the file
            {
              vector<unsigned long int>v1;
              vector<unsigned long int>v2;
              string s;
              getline(ist,s);
              for(int i=0;i<s.size();i++)
              v1.push_back(static_cast<int>(s[i]));//convert the char to an interger
              for(int i=0;i<v1.size();i++)
              v2.push_back(v1[i]<<i);//Shift each unsigned long left by its index
              int value=0;
              for(int i=0;i<v2.size();i++)
                value=value^v2[i];//use the operator exclusive to calculate the value
              cout<<value<<'\n';
            }
  return 0;
}
catch(exception&e)// catch exception
{
        cerr<<"error:"<<e.what()<<'\n';
        return 1;
}
catch(...)
{
        cerr<<"Oops:unknown exception!\n";
        return 2;
}




