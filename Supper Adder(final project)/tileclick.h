#ifndef tileclick_H
#define tileclick_H

#include "GUI.h"
#include "Window.h"
#include <algorithm>
#include "std_lib_facilities_4.h"
#include "Calculator.h"
#include "Third_window.h"

using namespace Graph_lib;

class tbutton : public Button
{
public:
    tbutton(int X, int Y, int W, int H, Callback cb, const char* L = 0, int id = 0);
    int getid();
    void setid(int new_id);
private:
    int id;
};

class tileclick {
public:
	int goodbuttons;
    tileclick(int x, int y, int x_spacing, int y_spacing, int x_tile_size, int y_tile_size, Graph_lib::Window* win);
	~tileclick();
    void redraw();
    void add_buttons(vector<string> names);
    void move_to_bottom();
    void move_to_top();
    void toggle_button(string value);
    vector<Graph_lib::Button*> get_bottom();
    void set_total(const char* text);
	string get_total();
	void detach();
	static void doNothing(Address,Address);
	void tile_cb1();
	void tile_cb2();
	void tile_cb3();
	void tile_cb4();
	void tile_cb5();
	void tile_cb6();
	void tile_cb7();
private:
	Calculator calc;
    vector<tbutton*> top;
    vector<Graph_lib::Button*> bottom;
	Graph_lib::Window* winp;
	string score;
    int x;
    int top_y;
    int x_spacing;
    int y_spacing;
    int x_tile_size;
    int y_tile_size;
    int bottom_y;
	Graph_lib::Out_box* total;
	void tile_move(string value);
	
	static void cb1(Address,Address);
	static void cb2(Address,Address);
	static void cb3(Address,Address);
	static void cb4(Address,Address);
	static void cb5(Address,Address);
	static void cb6(Address,Address);
	static void cb7(Address,Address);

};

#endif