//Jialu Zhao
//CSCE 121-508
//Due: October 4, 2016 
//hw4pr3.cpp
#include"std_lib_facilities_4.h"
void print(vector<int>& v, const string& name)
{
	cout << name << ": (" << v.size() << ") {";
	for (int i = 0; i<v.size(); ++i) {
		cout << v[i];
		if (i<v.size()-1) cout << ", ";	// avoid a trailing comma
	}
	cout << "\n}\n";
}

void fibonacci(int x, int y, vector<int>& v, int n)
{
	// first deal with n when n is small
	if (n<1) return;
	if (1<=n) v.push_back(x);
	if (1<=2) v.push_back(y);
	//now deal with the real n
	for (int i=2; i<n; ++i) {	//start with 2, because v[0]=x,v[1]=y
		int z = x+y;	// next element
		v.push_back(z);
		x = y;	// move the sequence on
		y = z;
	}
}


int main()
try
{
	cout<< "please enter two integer values (to be used to start a Fibinacci series) and the number of elements of the series: ";
	int val1 = 0;
	int val2 = 0;
	int n;
	while (cin>>val1>>val2>>n) {	// read three integers
		vector<int> vf;
		fibonacci(val1,val2,vf,n);
		cout << "fibonnaci(" << val1 << "," << val2 << ") ";
		print(vf,"");
		 cout<<"the square root of the ratio of the last element of v is"<<sqrt((double)(vf[n-1])/(double)(vf[n-3]))<<endl;
		cout << "Try again: ";
	}
}
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
