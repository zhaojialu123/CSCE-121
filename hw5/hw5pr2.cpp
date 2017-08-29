//Jialu Zhao
//CSCE 121-508
//Due: October 11, 2016
//hw5pr2.cpp
#include "std_lib_facilities_4.h"	
enum Base { octal, decimal, hexadecimal };
void write(Base b, int x)
{
	cout.setf(ios_base::left,ios_base::adjustfield);	//in oder to use setw
	switch (b) {//sort by base
	case octal:
		cout << oct << setw(15) << x << "octal       converts to ";
		break;
	case decimal:
		cout << dec << setw(15) << x << "decimal     converts to ";
		break;
	case hexadecimal:
		cout << hex << setw(15) << x << "hexadecimal converts to ";
		break;
	}     
	cout << dec << setw(15) << x << "decimal\n";
}


int main()
{
	try
	{
		int x;
		cin.unsetf(ios::dec);	//don't assume decimal
		cin.unsetf(ios::oct);//don't assume octal
		cin.unsetf(ios::hex);//don't assume hexadecimal
		cout << showbase;	// //prefix 0 for octal and 0x for hexadecimal
		cout << "Please enter octal, decimal, and hexadecimal numbers: \n";
		char ch;
		while (cin.get(ch)) 
		{
			if (ch=='0') 
			{
				cin.get(ch);
				if (ch=='x' || ch=='X') {	// read hexadecimal
					cin>>hex>>x;
					write(hexadecimal,x);
				}
				else 
				if (isdigit(ch))
				{	// read octal
					cin.unget();	// put character back
					cin>>oct>>x;
					write(octal,x);
				}
				else {	//if 0 is an octal
					cin.unget();	// put character back
					write(octal,0);
				}
			}
			else 
			if (isdigit(ch)) {	// read decimal
				cin.unget();	// put character back
				cin>>dec>>x;
				write(decimal,x);
			}
			if(ch=='q')
			break;
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
