//Jialu Zhao
//CSCE 121-508
//Due: October 25, 2016
//hw6pr3.cpp
#include"Graph.h"
#include"Window.h"
#include"Simple_window.h"
using namespace Graph_lib;
class Scandinavian_flag : public Shape{
	public:
	Scandinavian_flag(Color c1, Color c2):
		rect1(Point(0,0), 500,300),
		rect2(Point(0,120), 500,60),
		rect3(Point(150,0), 60,300)//constructor
	{
		/* set the colors of the rectangles */
		rect1.set_fill_color(c1);
		rect2.set_fill_color(c2);
		rect2.set_color(Color::invisible);
		rect3.set_fill_color(c2);
		rect3.set_color(Color::invisible);
	}

	Rectangle rect1, rect2, rect3;
	/* Color first, second,third; */

	void draw_lines() const {
		rect1.draw_lines(); //background of flag
		rect2.draw_lines(); // horizontal bar
		rect3.draw_lines(); // vertical bar
	}
};

int main(){
	try{
		using namespace Graph_lib;
		Point tl(150,150);
		Simple_window win(tl,600,400,"My window");//set up my window
		Scandinavian_flag Denmark(Color::red,Color::white);
		win.attach(Denmark);
		Text t1{Point{250,330},"Denmark"};
		win.attach(t1);
	    gui_main();
		//win.wait_for_button();//draw the first flag with name underneath
		win.detach(Denmark);
		win.detach(t1);//erase the first flag
		Fl::redraw();
		Scandinavian_flag Finland(Color::white,Color::blue);
		win.attach(Finland);
		Text t2{Point{250,330},"Finland"};
		win.attach(t2);
		Fl::redraw();//draw the second flag with name underneath
		win.detach(Finland);
		win.detach(t2);//erase the second flag
		Scandinavian_flag Sweden(Color::blue,Color::yellow);
		win.attach(Sweden);
		Text t3{Point{250,330},"Sweden"};
		win.attach(t3);
		win.wait_for_button();//draw the thrid flag with name underneath
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

