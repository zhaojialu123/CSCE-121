//Jialu Zhao
//CSCE 121-508
//Due: October 4, 2016 
//hw4pr4.cpp// Chrono.cpp 
#include "Chrono.h"
namespace Chrono { 
// member function definitions:
Date::Date(int yy, Month mm, int dd)           
     : y{yy}, m{mm}, d{dd}
{
          if (!is_date(yy,mm,dd)) throw Invalid{}; }
const Date& default_date()
{
          static Date dd {2001,Month::jan,1}; //satrt of 21st century          
          return dd;
}
Date::Date()           
     :y{default_date().year()},           
     m{default_date().month()},           
     d{default_date().day()}
{
}
void Date:: add_day(int n) {
    while(n--)
    {  
            if(leapyear(y))
            {
            switch(m){
            case Month(1):case Month(3):case Month(5):case Month(7):case Month(8):case Month(10):
            {
                if(d>30)
                {
                d=1;
                int hold = int(m);
                hold++;
                m = Month(hold);
                }
                else
                d=d+1;
            } break;
            case Month(2):{
                if(d>28)
                {
                d=1;
                int hold = int(m);
                hold++;
                m = Month(hold);
                }
                else
                d=d+1;
            } break;
            case Month(4):case Month(6):case Month(9):case Month(11):
            {   
                if(d>29)
                {
                d=1;
                int hold = int(m);
                hold++;
                m = Month(hold);
                }
                else
                d=d+1;
            } break;
            case Month(12):
            {  
                if(d>30)
                {
                d=1;
                m=Month(1);
                y=y+1;
                }
                else
                d=d+1;
            }break;
        }
        }
        else
        {   
            switch(m){
            case Month(1):case Month(3):case Month(5):case Month(7):case Month(8):case Month(10):
            {
                if(d>30)
                {
                d=1;
                int hold = int(m);
                hold++;
                m = Month(hold);
                }
                else
                d=d+1;
            } break;
            case Month(4):case Month(6):case Month(9):case Month(11):
            {   
                if(d>29)
                {
                d=1;
                int hold = int(m);
                hold++;
                m = Month(hold);
                }
                else
                d=d+1;
            } break;
            case Month(12):
            {  
                if(d>30)
                {
                d=1;
                m=Month(1);
                y=y+1;
                }
                else
                d=d+1;
            }break;
            case Month(2):
            {
                if(d>27)
                {
                d=1;
                int hold = int(m);
                hold++;
                m = Month(hold);
                }
                else
                d=d+1;
            }break;
        }
          // . . .
}

}
}
void Date::add_month(int n) {
          // . . .
}
void Date::add_year(int n)
{
          if (m==Month::feb && d==29 && !leapyear(y+n)) {// beware of leap years!
                    m = Month::mar; //use March 1 instead of February 29                    
                    d = 1;           
          }
          y+=n;
}
// helper functions:
bool is_date(int y, Month m, int d) 
{
          // assume that y is valid
          if(d<=0) return false;// d must be positive 
          if(m<Month::jan||Month::dec<m){ Month mm = m ;return false;}          
          int days_in_month = 31; // most months have 31 days
          switch (m) {
          case Month::feb: // the length of February varies                     
                    days_in_month = (leapyear(y))?29:28;
                    break;
          case Month::apr: case Month::jun: case Month::sep: case Month::nov:                     
          days_in_month = 30;               // the rest have 30 days                     
          break;
          }
          if (days_in_month<d) return false;           
          return true;
}
bool leapyear(int y) 
{

   if(y%4==0)
   {
       if(y%100==0)
       {
           if(y%400==0)
              return true;
           //cout<<y<<"is a leap year.\n";
           else
               return false;
       }
       else
           return true;
   }
   else
           return false;

//return true;
}
bool operator==(const Date& a, const Date& b) 
{
 
          return a.year()==b.year()
                    && a.month()==b.month()                    
                    && a.day()==b.day();
}
bool operator!=(const Date& a, const Date& b) {
          return !(a==b);
}
ostream& operator<<(ostream& os, const Date& d) 
{
          return os << '(' << d.year()                               << ',' << (int)(d.month())                            
          << ',' << d.day() << ')';
}
istream& operator>>(istream& is, Date& dd) 
{
          int y, m, d;
          char ch1, ch2, ch3, ch4;
          is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;           
          if (!is) return is;
          if (ch1!= '(' || ch2!=',' || ch3!=',' || ch4!=')') { //oops: format error                    
               is.clear(ios_base::failbit);           
          return is;
          }
          dd = Date(y, Month(m),d); //update dd          
          return is;
}

void Date:: day_of_week() {//Zeller's congruence
enum  Month {
          jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
  int mm = Month(m);
  int q=d;
 if (mm == 1 || mm == 2) {
   mm = mm + 12;
   y = y - 1;
  }
 
  int j = y / 100;
  int k = y % 100;
  int h = (q + 26 * (mm + 1) / 10 + k + k / 4 + j / 4 + 5 * j) % 7;
    switch(h)
    {
        case 0 : printf("That is a Saturday.\n"); break;
        case 1 : printf("That is a Sunday.\n"); break;
        case 2 : printf("That is a Monday. \n"); break;
        case 3 : printf("That is a Tuesday. \n"); break;
        case 4 : printf("That is a Wednesday. \n"); break;
        case 5 : printf("That is a Thursday. \n"); break;
        case 6 : printf("That is a Friday. \n"); break;
    }
     
          // . . .
        //  return Day::sunday;
}
Date next_Sunday(const Date& d) {
          // ...
          return d;
}
Date next_weekday(const Date& d) {
          // . . .
          return d;
}



} // Chrono