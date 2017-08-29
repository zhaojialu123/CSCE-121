//Jialu Zhao
//CSCE 121-508
//Due: October 11, 2016
//hw5pr1.cpp
#include"std_lib_facilities_4.h"
void fill_vector(istream& ist, vector<string>& v)           
{
          vector<string>v2;
          while(!ist.eof())//until end of the file continuously read the line
          {
              string s;
              getline(ist,s);//one time get one line
              v2.push_back(s);//make every line be a string element in the vector
          }
          for(int i=0;i<v2.size();i++)//for every line in the words
          {
              string helper="";
              for(int j=0;j<v2[i].size();j++)//for evey characters in one line
              {
                  if(v2[i][j]!=' ')//
                  {
                      helper+=v2[i][j];
                  }
                  else
                  {
                    v.push_back(helper);
                      v.push_back(" ");
                      helper="";
                  }

              }
              if(helper!= "")//push the last word back
              v.push_back(helper);
            v.push_back("\n");// push new line back
          }
          for (string s; ist >> s; ) v.push_back(s);
          if (ist.eof()) return; // fine: we found the end of file
          if (ist.bad()) error("ist is bad"); // stream corrupted; let’s get out of here!           
          if (ist.fail())
           {            // clean up the mess as best we can and report the problem                     
                    ist.clear(); // clear stream state,so that we can look for terminator
          } 
}
int main()
{
try{
    ifstream ist {"in.txt"};//reading file from in.txt
    vector<string> words;//declare a vector include the string words
    fill_vector(ist,words);//put all the words in the vector include space
    int n=words.size();
    for(int i=0;i<n;i++)
    {
        if(words[i]==" "||words[i]=="\n");
        else{
            vector<char> v3( words[i].begin(), words[i].end() );//put every words in the string vectors to a char vector
            int m=v3.size();
            if(tolower(v3[0])=='a'||tolower(v3[0])=='e'||tolower(v3[0])=='i'||tolower(v3[0])=='o'||tolower(v3[0])=='u')//tranlate to pig latin language
                {
                    v3.push_back('w');
                    v3.push_back('a');
                    v3.push_back('y');
                
                string temp_;
                for(int b=0;b<v3.size();b++)
                        temp_ += v3[b];//push back every charatcers into a string
                    words[i]=temp_;
                }
                
            else{//not vewel
                    while(true)
                    {
                        for(int a=0;a<m;a++)
                        {
                            if(tolower(v3[0])=='a'||tolower(v3[0])=='e'||tolower(v3[0])=='i'||tolower(v3[0])=='o'||tolower(v3[0])=='u')
                                break;
                            v3.push_back(v3[0]);//push the first character back 
                            v3.erase(v3.begin());//delete the first character and the second one become the fisrt one
                        }
                        if(tolower(v3[0])=='a'||tolower(v3[0])=='e'||tolower(v3[0])=='i'||tolower(v3[0])=='o'||tolower(v3[0])=='u')
                        break;
                    }
                    v3.push_back('a');
                    v3.push_back('y');
                    string temp_;
                    for(int b=0;b<v3.size();b++)
                        temp_ += v3[b];
                    words[i]=temp_;
                }
    }
    ofstream ost {"out.txt"};
    for(int c=0;c<words.size();c++)
        ost<<words[c];
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
    



