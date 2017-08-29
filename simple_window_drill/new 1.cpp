#include"Graph.h"
#include"Simple_window.h"
using namespace Graph_lib;
int main()
{	Point tl(150,150);
	Simple_window win(tl,600,400,"My window");
	Lines x;
	x.add(Point{100,100},Point{100,300});
	x.add(Point{50,300},Point{100,300});
	x.add(Point{50,300},Point{50,250});
	x.add(Point{400,100},Point{500,100});
	x.add(Point{500,100},Point{400,300});
	x.add(Point{400,300},Point{500,300});
	win.attach(x);
	Graph_lib::Polygon poly;
    poly.add(Point(300,200));
    poly.add(Point(275,175));
    poly.add(Point(350,100));
    poly.add(Point(425,175));
    poly.add(Point(400,200));
	win.attach(poly);
	win.wait_for_button();
}