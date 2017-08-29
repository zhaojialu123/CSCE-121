#pragma once
#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities_4.h"
#include "GUI.h"
#include "Third_window.h"
using namespace Graph_lib;

struct Third_window;

struct Second_window : Graph_lib::Window{
    Second_window(Point xy, int w, int h, Third_window* next_win,const string& title);
private:
    Text t1;
    Image p1;
    Image p2;
    string s;
    Vector<Text*>scores3;
    Vector<Text*>scores4;
    Vector<Text*>scores5;
    Vector<Text*>scores6;
    Vector<Text*>scores7;
    Vector<Text*>initials;
    Button next_button1;
    Button next_button2;
    Button quit_button;
    In_box nickname;
    Third_window* win3;
	
    void next1();
    void next2();
    void quit();
	
    //callback functions
	static void cb_next1(Address,Address); 
	static void cb_next2(Address,Address);
	static void cb_quit(Address,Address);
};