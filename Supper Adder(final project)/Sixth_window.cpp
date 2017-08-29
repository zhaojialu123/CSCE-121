#include "Sixth_window.h"

Sixth_window::Sixth_window(Point xy, int w, int h, const string& title)
        :Window(xy,w,h,title),
        t{Point{150,50},"Do you want to play another game?"},
        p1{Point{135,120},"picture.jpeg"},
        quit_button(Point(200,350),70,20,"Quit",cb_quit),
        next_button(Point(300,350),70,20,"Continue",cb_next)
{
            
	t.set_font_size(20);
	t.set_color(Color::blue);
	attach(t);
	attach(next_button);
	attach(quit_button);
	attach(p1);
	redraw();
}
        

void Sixth_window::cb_next(Address,Address pw)
{
        reference_to<Sixth_window>(pw).next();
}

void Sixth_window::next()//reopen second window
{
	hide();
    win3->show();
}

void Sixth_window::cb_quit(Address, Address pw)
{
    reference_to<Sixth_window>(pw).quit();
}

void Sixth_window::quit()
{
    hide();
}

void Sixth_window::setNextWin(Second_window* nextwin) //so that can declare second window to sixth window
{
	win3 = nextwin;
}
