//Jialu Zhao
//CSCE 121-508
//Due: October 25, 2016
//hw6pr4.cpp
#include"Graph.h"
#include"Window.h"
#include"Simple_window.h"
using namespace Graph_lib;
class flag : public Shape{
	public:
	flag(Color c1, Color c2,Color c3):
		rect1(Point{0,0},500,100),
        rect2(Point{0,100},500,100),
        rect3(Point{0,200},500,100)
	{
		/* set the colors of the rectangles */
		rect1.set_fill_color(c1);
		rect2.set_fill_color(c2);
		rect3.set_fill_color(c3);
	}//constructor

	Rectangle rect1, rect2, rect3;
	/* Color first, second; */

	void draw_lines() const {
		rect1.draw_lines(); //first bar
		rect2.draw_lines(); // second bar
		rect3.draw_lines(); // third bar
	}
};

int main(){
	try{
			Point tl(150,150);
			Simple_window win(tl,600,400,"My window");//set up my window
			win.show();
			Fl::redraw();
			Fl::wait();
		while(true)
		{
			flag Russia(Color::white,Color::blue,Color::red);
			win.attach(Russia);
			Text t1{Point{250,330},"Russia"};
			win.attach(t1);
			win.show();//draw the flag and show on the screen and then wait for window
			Fl::redraw();
			Fl::wait();
			system("sleep 5");
			win.detach(Russia);
			win.detach(t1);
			win.show();
			Fl::redraw();
			Fl::wait();
			flag Lithuania(Color::yellow,Color::green,Color::red);
			win.attach(Lithuania);
			Text t2{Point{250,330},"Lithuania"};
			win.attach(t2);
			win.show();
			Fl::redraw();
			Fl::wait();
			system("sleep 5");
			win.detach(Lithuania);
			win.detach(t2);
			win.show();
			Fl::redraw();
			Fl::wait();
			flag Austria(Color::red,Color::white,Color::red);
			win.attach(Lithuania);
			Text t3{Point{250,330},"Austria"};
			win.attach(t3);
			win.show();
			Fl::redraw();
			Fl::wait();
			system("sleep 5");
			win.detach(Austria);
			win.detach(t3);
			win.show();
			Fl::redraw();
			Fl::wait();
			flag Yemen(Color::red,Color::white,Color::black);
			win.attach(Yemen);
			Text t4{Point{250,330},"Yemen"};
			win.attach(t4);
			win.show();
			Fl::redraw();
			Fl::wait();
			system("sleep 5");
			win.detach(Yemen);
			win.detach(t4);
			win.show();
			Fl::redraw();
			Fl::wait();
			flag Bolivia(Color::red,Color::yellow,Color::green);
			win.attach(Bolivia);
			Text t5{Point{250,330},"Bolivia"};
			win.attach(t5);
			win.show();
			Fl::redraw();
			Fl::wait();
			system("sleep 5");
			win.detach(Bolivia);
			win.detach(t5);
			win.show();
			Fl::redraw();
			Fl::wait();
		}
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
	