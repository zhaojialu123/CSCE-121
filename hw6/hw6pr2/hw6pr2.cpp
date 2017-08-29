//Jialu Zhao
//CSCE 121-508
//Due: October 25, 2016
//hw6pr2.cpp
#include"Graph.h"
#include"Simple_window.h"
#include"std_lib_facilities_4.h"
using namespace Graph_lib;
using namespace std::chrono;
//linear congruential pseudorandom number generator
int randint()
{
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
        Point tl(150,150);
        Simple_window win(tl,850,700,"My window");
        Axis xa {Axis::x, Point{50,600}, 700, 7, "frequency"};                                                                         
        win.attach(xa); 
        win.set_label("my windows");
        Axis ya {Axis::y, Point{50,600}, 550, 11, "the last digit"};                                                                         
        win.attach(ya); //set up coordinates
        Text t100{Point{140,612},"100"};
        Text t200{Point{240,612},"200"};
        Text t300{Point{340,612},"300"};
        Text t400{Point{440,612},"400"};
        Text t500{Point{540,612},"500"};
        Text t600{Point{640,612},"600"};
        Text t700{Point{740,612},"700"};//axis x label
        t100.set_color(Color::blue);
        t200.set_color(Color::blue);
        t300.set_color(Color::blue);
        t400.set_color(Color::blue);
        t500.set_color(Color::blue);
        t600.set_color(Color::blue);
        t700.set_color(Color::blue);//set x label color
        win.attach(t100);
        win.attach(t200);
        win.attach(t300);
        win.attach(t400);
        win.attach(t500);
        win.attach(t600);
        win.attach(t700);//attach x label on windows
        Text t0{Point{25,556},"0"};
        Text t1{Point{25,506},"1"};
        Text t2{Point{25,456},"2"};
        Text t3{Point{25,406},"3"};
        Text t4{Point{25,356},"4"};
        Text t5{Point{25,306},"5"};
        Text t6{Point{25,256},"6"};
        Text t7{Point{25,206},"7"};
        Text t8{Point{25,156},"8"};
        Text t9{Point{25,106},"9"};//axis y label
        t0.set_color(Color::red);
        t1.set_color(Color::red);
        t2.set_color(Color::red);
        t3.set_color(Color::red);
        t4.set_color(Color::red);
        t5.set_color(Color::red);
        t6.set_color(Color::red);
        t7.set_color(Color::red);
        t8.set_color(Color::red);
        t9.set_color(Color::red);//set y label color
        win.attach(t0);
        win.attach(t1);
        win.attach(t2);
        win.attach(t3);
        win.attach(t4);
        win.attach(t5);
        win.attach(t6);
        win.attach(t7);
        win.attach(t8);
        win.attach(t9);//attach y label on windows
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
            for(int i=0;i<5000;i++)//call randint 5000 times
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
            }
            Rectangle rect0{Point{50,535},i0,30};
            Rectangle rect1{Point{50,485},i1,30};
            Rectangle rect2{Point{50,435},i2,30};
            Rectangle rect3{Point{50,385},i3,30};
            Rectangle rect4{Point{50,335},i4,30};
            Rectangle rect5{Point{50,285},i5,30};
            Rectangle rect6{Point{50,235},i6,30};
            Rectangle rect7{Point{50,185},i7,30};
            Rectangle rect8{Point{50,135},i8,30};
            Rectangle rect9{Point{50,85},i9,30};//set up rectangle which width is the frequency
            rect0.set_fill_color(Color::green);
            rect1.set_fill_color(Color::green);
            rect2.set_fill_color(Color::green);
            rect3.set_fill_color(Color::green);
            rect4.set_fill_color(Color::green);
            rect5.set_fill_color(Color::green);
            rect6.set_fill_color(Color::green);
            rect7.set_fill_color(Color::green);
            rect8.set_fill_color(Color::green);
            rect9.set_fill_color(Color::green);//set up rectangle color
            win.attach(rect0);
            win.attach(rect1);
            win.attach(rect2);
            win.attach(rect3);
            win.attach(rect4);
            win.attach(rect5); 
            win.attach(rect6);
            win.attach(rect7);
            win.attach(rect8);
            win.attach(rect9);//attach rectangle to the windows
            Text t01{Point{i0+60,556},std::to_string(i0)};
            Text t02{Point{i1+60,506},std::to_string(i1)};
            Text t03{Point{i2+60,456},std::to_string(i2)};
            Text t04{Point{i3+60,406},std::to_string(i3)};
            Text t05{Point{i4+60,356},std::to_string(i4)};
            Text t06{Point{i5+60,306},std::to_string(i5)};
            Text t07{Point{i6+60,256},std::to_string(i6)};
            Text t08{Point{i7+60,206},std::to_string(i7)};
            Text t09{Point{i8+60,156},std::to_string(i8)};
            Text t10{Point{i9+60,106},std::to_string(i9)};
            win.attach(t01);
            win.attach(t02);
            win.attach(t03);
            win.attach(t04);
            win.attach(t05);
            win.attach(t06);
            win.attach(t07);
            win.attach(t08);
            win.attach(t09);
            win.attach(t10);//put the value aside the rectangles
        win.wait_for_button();
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