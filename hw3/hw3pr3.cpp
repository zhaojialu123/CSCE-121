//Jialu Zhao
//CSCE 121-508
//Due: September 22, 2016
//hw3pr3.cpp
#include"std_lib_facilities_4.h"
using namespace std::chrono;
//linear congruential pseudorandom number generator
int randint(){
        //use the clock for an initial pseudorandom number
        static long x = time_point_cast<microseconds>(system_clock::now())
			.time_since_epoch().count() & 0x7fffffff; //CORRECTED
        //calculate the next pseudorandom number
        x = (1103515245 * x + 12345) & 0x7fffffff;    //parameters from glibc(?)
        return x;
}
int main()
{
    try{
        int i0=0;// define count number i0 for the last digit is a 0.
        int i1=0;// define count number i1 for the last digit is a 1.
        int i2=0;// define count number i2 for the last digit is a 2.
        int i3=0;// define count number i3 for the last digit is a 3.
        int i4=0;// define count number i4 for the last digit is a 4.
        int i5=0;// define count number i5 for the last digit is a 5.
        int i6=0;// define count number i6 for the last digit is a 6.
        int i7=0;// define count number i7 for the last digit is a 7.
        int i8=0;// define count number i8 for the last digit is a 8.
        int i9=0;// define count number i9 for the last digit is a 9.
        for(int i=0;i<1000000;i++)//call randint 10000000 times
        {
            switch(randint()%10)
            {
                case 0:
                    i0++;
                    break;
                case 1:
                    i1++;
                    break;
                case 2:
                    i2++;
                    break;
                case 3:
                    i3++;
                    break;
                case 4:
                    i4++;
                    break;
                case 5:
                    i5++;
                    break;
                case 6:
                    i6++;
                    break;
                case 7:
                    i7++;
                    break;
                case 8:
                    i8++;
                    break;
                case 9:
                    i9++;
                    break;
            }
        }// switch random numbers and count the quantity through the last digit of each number using reminder after numbers divide by 10
        cout<<"There were "<<i0<<" 0's\n";
        cout<<"There were "<<i1<<" 1's\n";
        cout<<"There were "<<i2<<" 2's\n";
        cout<<"There were "<<i3<<" 3's\n";
        cout<<"There were "<<i4<<" 4's\n";
        cout<<"There were "<<i5<<" 5's\n";
        cout<<"There were "<<i6<<" 6's\n";
        cout<<"There were "<<i7<<" 7's\n";
        cout<<"There were "<<i8<<" 8's\n";
        cout<<"There were "<<i9<<" 9's\n";
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

  
