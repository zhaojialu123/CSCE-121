#include "tileclick.h"

using namespace Graph_lib;

tbutton::tbutton(int X, int Y, int W, int H, Callback cb, const char* L, int id)
    : Button(Point{X,Y}, W, H, L, cb)
    , id(id)
{
}

int tbutton::getid()
{
    return id;
}

void tbutton::setid(int new_id)
{
    id = new_id;
}

tileclick::tileclick(int x, int y, int x_spacing, int y_spacing, int x_tile_size, int y_tile_size, Graph_lib::Window* win)
    : x(x)
    , top_y(y)
    , x_spacing(x_spacing)
    , y_spacing(y_spacing)
    , x_tile_size(x_tile_size)
    , y_tile_size(y_tile_size),
	winp(win)
{
    bottom_y = y + y_tile_size + y_spacing;
	total = new Out_box(Point{10,10},100,20,"0");
	winp->attach(*total);
	total->hide();
}

tileclick::~tileclick()
{
    delete total;

    for(tbutton* b : top)
        delete b;

    for(Graph_lib::Button* b : bottom)
        delete b;
}

void tileclick::add_buttons(vector<string> names)
{
	goodbuttons = names.size();
	//create 7 buttons without label or attaching
	tbutton* one = new tbutton(x + x_spacing, top_y, x_tile_size, y_tile_size, cb1, "0", 1);
	top.push_back(one);
	tbutton* two = new tbutton(x + x_spacing * 2, top_y, x_tile_size, y_tile_size, cb2, "0", 2);
	top.push_back(two);
	tbutton* three = new tbutton(x + x_spacing * 3, top_y, x_tile_size, y_tile_size, cb3, "0", 3);
	top.push_back(three);
	tbutton* four = new tbutton(x + x_spacing * 4, top_y, x_tile_size, y_tile_size, cb4, "0", 4);
	top.push_back(four);
	tbutton* five = new tbutton(x + x_spacing * 5, top_y, x_tile_size, y_tile_size, cb5, "0", 5);
	top.push_back(five);
	tbutton* six = new tbutton(x + x_spacing * 6, top_y, x_tile_size, y_tile_size, cb6, "0", 6);
	top.push_back(six);
	tbutton* seven = new tbutton(x + x_spacing * 7, top_y, x_tile_size, y_tile_size, cb7, "0", 7);
	top.push_back(seven);
	for (unsigned int i = 0; i < names.size();i++) //for number of labels sent, set labels and show those
	{
		top[i]->label=names[i];
		winp->attach(*top[i]);
	}
}

void tileclick::toggle_button(string value)
{
	Graph_lib::Button* b= new Button(Point{x+bottom.size()*x_spacing,bottom_y},x_tile_size,y_tile_size,value, doNothing);
	winp->attach(*b);
	bottom.push_back(b);
}

void tileclick::doNothing(Address,Address) //runs well
{
}

void tileclick::redraw()
{
    for (unsigned int i = 0; i < goodbuttons; i++) {
        top[i]->hide();
        top[i]->move(x + x_spacing * i, top_y);
        top[i]->show();
    }

    for (unsigned int i = 0; i < bottom.size(); i++) {
        bottom[i]->hide();
        bottom[i]->move(x + x_spacing * i, bottom_y);
        bottom[i]->show();
    }
}

vector<Graph_lib::Button*> tileclick::get_bottom()
/*
    Return vector of bottom buttons
*/
{
    return bottom;
}

void tileclick::set_total(const char *text)
/*
    Set text of total output
*/
{
	total->show();
    total->put(text);
}

string tileclick::get_total()
{
	return score;
}

void tileclick::tile_move(string value)
{
	toggle_button(value); //create new button on bottom row

	string expression;
	int tot =0;
	
	for (int i=0; i< bottom.size(); i++) { // for loop to build expression string
        expression += bottom[i]->label; 
    }
    expression = expression + "=";
	
    try 
	{ 
        tot = calc.calculate_total(expression); 
    } 
	catch(logic_error &e) 
	{
        cout << "Error: " << e.what() << endl;
     	tot = 0; 
    };
	score = to_string(tot);
    set_total(to_string(tot).c_str()); // set output to total of expression
	winp->redraw();//redraw window;
}

void tileclick::detach()
{
	for(int i =0; i < goodbuttons; i++)
	{
		winp->detach(*top[i]);
		delete top[i];
	}
	
	for(auto but:bottom) // 2 new features in the c++14/17 standard
	{
		winp->detach(*but);
		delete but;
	}
	top.clear();
	bottom.clear();
	goodbuttons = 0;
	set_total("");
	total->hide();
}

void tileclick::tile_cb1()
{
	top[0]->hide();
	string x = top[0]->label;
	tile_move(x);
}

void tileclick::tile_cb2()
{
	top[1]->hide();
	string x = top[1]->label;
	tile_move(x);
}

void tileclick::tile_cb3()
{
	top[2]->hide();
	string x = top[2]->label;
	tile_move(x);
}

void tileclick::tile_cb4()
{
	top[3]->hide();
	string x = top[3]->label;
	tile_move(x);
}

void tileclick::tile_cb5()
{
	top[4]->hide();
	string x = top[4]->label;
	tile_move(x);
}

void tileclick::tile_cb6()
{
	top[5]->hide();
	string x = top[5]->label;
	tile_move(x);
}

void tileclick::tile_cb7()
{
	top[6]->hide();
	string x = top[6]->label;
	tile_move(x);
}

void tileclick::cb1(Address,Address pw)
{
	reference_to<Third_window>(pw).selector->tile_cb1();
}

void tileclick::cb2(Address,Address pw)
{
	reference_to<Third_window>(pw).selector->tile_cb2();
}

void tileclick::cb3(Address,Address pw)
{
	reference_to<Third_window>(pw).selector->tile_cb3();
}

void tileclick::cb4(Address,Address pw)
{
	reference_to<Third_window>(pw).selector->tile_cb4();
}

void tileclick::cb5(Address,Address pw)
{
	reference_to<Third_window>(pw).selector->tile_cb5();
}

void tileclick::cb6(Address,Address pw)
{
	reference_to<Third_window>(pw).selector->tile_cb6();
}

void tileclick::cb7(Address,Address pw)
{
	reference_to<Third_window>(pw).selector->tile_cb7();
}