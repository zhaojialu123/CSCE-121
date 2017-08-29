//Jialu Zhao
//CSCE 121-508
//Due: September 8, 2016 
//hw1pr3.cpp
#include"std_lib_facilities_4.h"





int main(){
	
	
	int pennies,nickels,dimes,quarters,halfdollars,dollars,value;
	double value1;
	cout<<"How many pennies do you have?\n";
	cin>>pennies;
	if(pennies>1)
		cout<<"You have "<<pennies<<" pennies\n";
	else
		cout<<"You have "<<pennies<<" penny\n";//make the output grammatically correct.

	cout<<"How many nickels do you have?\n";
	cin>>nickels;
	if(nickels>1)
		cout<<"You have "<<nickels<<" nickels\n";
	else
		cout<<"You have "<<nickels<<" nickel\n";//make the output grammatically correct.
	
	cout<<"How many dimes do you have?\n";
	cin>>dimes;
	if(dimes>1)
		cout<<"You have "<<dimes<<" dimes\n";
	else
		cout<<"You have "<<dimes<<" dime\n";//make the output grammatically correct.
	
	cout<<"How many quarters do you have?\n";
	cin>>quarters;
	if(quarters>1)
		cout<<"You have "<<quarters<<" quarters\n";
	else
		cout<<"You have "<<quarters<<" quarter\n";//make the output grammatically correct.
	
	cout<<" How many half dollars do you have?\n";
	cin>>halfdollars;
	if(halfdollars>1)
		cout<<"You have "<<halfdollars<<" half dollars\n";
	else
		cout<<"You have "<<halfdollars<<" half dollar\n";//make the output grammatically correct.
	
	cout<<" How many dollars do you have?\n";
	cin>>dollars;
	if(dollars>1)
		cout<<"You have "<<dollars<<" dollars\n";
	else
		cout<<"You have "<<dollars<<" dollar\n";//make the output grammatically correct.
	


	value=pennies+nickels*5+dimes*10+quarters*25+halfdollars*50+dollars*100;
	cout<<" The value of all of your coins is "<< value<<"cents\n";// show result in cents.
	value1 = value / 100.0;
	cout<<"The value of all your coins is" << value1 <<"dollars.\n";//show result in dollars.
}