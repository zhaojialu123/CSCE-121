#include "First_window.h"
#include "std_lib_facilities_4.h"
using namespace Graph_lib;

//main
//auto and range-based for used in tileclick.cpp::detach();

int main()
try {
    Sixth_window win6(Point(100,100),700,400,"SupperAdder");//closer or continue window
	Third_window win3(Point(100,100),700,400,&win6, "SupperAdder");//game level and game window
    Second_window win2(Point(100,100),700,400, &win3, "SupperAdder"); //name and high score windows
    First_window win1(Point(100,100),700,400,&win2, "SupperAdder"); //intro windows
	win6.setNextWin(&win2); //give sixth window reference to second window so continue button can reopen second window
    win2.hide(); //win1 or win6 will show win2
	win3.hide();//win2 will show win3
    win6.hide();//win3 will show win6
	
    return gui_main();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}