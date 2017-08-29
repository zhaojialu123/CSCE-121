#include "First_window.h"
#include <cassert>

First_window::First_window(Point xy, int w, int h, Second_window* next_win, const string& title)
        :Window(xy,w,h,title),
        t1{Point{100,100},"The Super Adder"},
        t2{Point{100,50},"Team number:28"},
        t3{Point{100,150},"Jialu Zhao"},
        t4{Point{100,250},"Zachary Stachowiak"}, 
        t5{Point{100,350},"Yixing Zhao"},
        t6{Point{130,100},"Do you want to start?"},
        t7{Point{50,50},"instructions: "},
        t8{Point{40,75},"1.The goal of this game is to score as many points as possible by creating the"},
		t9{Point{40,100},"     highest possible value using the numbers and mathematical operators given to you."},
		t10{Point{40,125},"2.Choosing your level will decide how many tiles you get."},
		t11{Point{40,150},"3.Click on a tile to move it into the equation line."},
		t12{Point{40,175},"4.Parenthesis must always be closed and will come as a set."},
		t13{Point{40,200},"5.Factorials only work up to 9, anything higher is worth zero."},
		t14{Point{40,225},"6.You may place a positive or negative operators in front of numbers."},
		t15{Point{40,250},"Good luck and Have fun!"},
		p1{Point{150,120},"picture1.jpg"},
        p2{Point{150,120},"picture2.jpg"},
        win2(next_win),
        quit_button(Point(200,350),70,20,"Quit",cb_quit),
        start_button(Point(300,350),70,20,"Start",cb_start),
        next_button1(Point(x_max()-250,0),70,20,"Next",cb_next1),
        next_button2(Point(x_max()-250,0),70,20,"Next",cb_next2),
        next_button3(Point(300,350),70,20,"Next",cb_next3)
{
	t1.set_font_size(50);
	t1.set_color(Color::red);
	attach(t1);
	attach(p1);
	attach(next_button1);
	t2.set_font_size(30);
	t2.set_color(Color::blue);
	t3.set_font_size(25);
	t3.set_color(Color::yellow);
	t4.set_font_size(25);
	t4.set_color(Color::yellow);
	t5.set_font_size(25);
	t5.set_color(Color::yellow); 
	t6.set_font_size(30);
	t6.set_color(Color::green);
}

void First_window::cb_start(Address,Address pw)
{
        reference_to<First_window>(pw).start();
}

void First_window::start() //set up instruction window
{
    detach(t6);
    detach(p2);
    attach(t7);
	attach(t8);
	attach(t9);
	attach(t10);
	attach(t11);
	attach(t12);
	attach(t13);
	attach(t14);
	attach(t15);
    attach(next_button3);
    detach(start_button);
    redraw();
}

void First_window::cb_next3(Address, Address pw)
{
    reference_to<First_window>(pw).next3();
}

void First_window::next3()//open second window
{
    hide();	
    win2->show();
}

void First_window::cb_next1(Address,Address pw)
{
        reference_to<First_window>(pw).next1();
}

void First_window::next1() //intro window
{
   detach(t1);
   detach(p1);
   attach(t2);
   attach(t3);
   attach(t4);
   attach(t5);
   detach(next_button1);
   attach(next_button2);
   redraw();
}

void First_window::cb_next2(Address,Address pw)
{
        reference_to<First_window>(pw).next2();
}

void First_window::next2() //team window
{
    detach(t2);
    detach(t3);
    detach(t4);
    detach(t5);
    detach(next_button2);
    attach(t6);
    attach(p2);
    attach(start_button);
    attach(quit_button);
    redraw();
}

void First_window::cb_quit(Address,Address pw)
{
        reference_to<First_window>(pw).quit();
}

void First_window::quit()
{
    hide();
}