//Jialu Zhao
//CSCE 121-508
//Due: October 11, 2016
//hw5pr3.cpp
#include"std_lib_facilities_4.h"
int main()
{
	try{
		ifstream ist ( "/usr/share/dict/words" );//read file from /usr/share/dict/words
		vector<string> dictionary;
		string words;
		while ( ist>> words )
		dictionary.push_back ( words );//put every words in the dictionary in the vector called words
		cout<<"Enter word:";
		string word;
		cin>>word;
		while(cin)//continuously to find a word in the verctor words
		{
			int a=0;
			for(int i=0;i<dictionary.size();i++)
			{
				if(word==dictionary[i])
					a=a+1;
			}
			if(a==1)
				cout<<"That word is in my dictionary.\n";
			else
				cout<<"That word is not in my dictionary.\n";
			cout<<"Enter word:";
			cin>>word;
		}
		return 0;
	}
	catch(exception&e){//exception handling
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


