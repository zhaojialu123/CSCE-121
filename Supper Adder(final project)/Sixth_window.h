#pragma once
#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities_4.h"
#include "GUI.h"
#include "Second_window.h"
using namespace Graph_lib;

struct Second_window;

struct Sixth_window : Graph_lib::Window{
    Sixth_window(Point xy, int w, int h, const string& title);

public:
	void setNextWin(Second_window* nextwin);
private:
    Text t;
    Image p1;
    Button next_button;
    Button quit_button;
	Second_window* win3;
    void next();
    void quit();
    
static void cb_next(Address, Address);  
static void cb_quit(Address, Address);
};
