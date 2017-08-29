#pragma once
#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities_4.h"
#include "GUI.h"
#include "Second_window.h"
using namespace Graph_lib;

struct First_window : Graph_lib::Window{
    First_window(Point xy, int w, int h, Second_window* next_win,const string& title);
    
private:
    Text t1;
    Text t2;
    Text t3;
    Text t4;
    Text t5;
    Text t6;
    Text t7;
	Text t8;
	Text t9;
	Text t10;
	Text t11;
	Text t12;
	Text t13;
	Text t14;
	Text t15;
    Image p1;
    Image p2;
    Second_window* win2;
    Button next_button1;
    Button next_button2;
    Button start_button;
    Button next_button3;
    Button quit_button;
    void start();
    void quit();
    void next1();
    void next2();
    void next3();
	static void cb_next1(Address, Address);  
	static void cb_next2(Address, Address);
	static void cb_next3(Address, Address);
	static void cb_start(Address, Address);
	static void cb_quit(Address, Address);
};