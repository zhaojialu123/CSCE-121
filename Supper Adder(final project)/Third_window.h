#ifndef Third_window_H
#define Third_window_H
#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities_4.h"
#include "GUI.h"
#include "tileclick.h"
#include "Sixth_window.h"
using namespace Graph_lib;

struct Sixth_window;
class tileclick;

struct Third_window : Graph_lib::Window{
    Third_window(Point xy, int w, int h, Sixth_window* next_win, const string& title);
    void level3();
    void level4();
    void level5();
    void level6();
    void level7();
    vector<string> outputs;
	string score;
	string name;
	tileclick* selector;
private:
	int difflevel;
    Text t1;
    Text t2;
    Text t;
    Button next_button3;
    Button next_button;
    In_box difficulty_level;
	Sixth_window* win6;
    void next();
    void next3();
	void set_game(vector<string> tiles);
	void savescore(int lvl);
	void tile_move(string value);
    
    //callback functions
	static void cb_next(Address,Address);
	static void cb_next3(Address,Address);
};

#endif