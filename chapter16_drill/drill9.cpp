// Chapter 16, drill
// GUI example: line drawing program

#include "Window.h"
#include "Graph.h"
#include "GUI.h"
using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
    Lines_window(Point xy, int w, int h, const string& title);
private:
    // data
    Circle cc;

    // widgets
    Button change_color_button;
    

    
    void change()
    {
       cc.set_fill_color(Color::red);
    }
    
    void button_pressed() 
    { 
        if(cc.color().as_int()==Color::black)
            ; 
        else
            change();
        redraw();
    }
    static void cb_next(Address, Address);

    // callback functions
    
   
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
    cc(Point{100,200},50),
    change_color_button(Point(x_max()-150,0),70,20,"change_color_button",cb_next)
{
    attach(change_color_button);
    attach(cc);
    
}
void Lines_window::cb_next(Address,Address pw){
    reference_to<Lines_window>(pw).button_pressed();
}

int main()
try {
    //Circle cc{Point{100,200},50};
    Lines_window win(Point(100,100),600,400,"lines");
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