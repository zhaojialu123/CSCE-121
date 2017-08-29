#include "Timer.h"

timer::timer(Point pp):Shape(),
t(pp,"0 seconds")
{
	counting = false;
	begin = 0;
	p = pp;
	draw_lines();
}

void timer::start()
{
	if (!counting)
	{
		begin = clock();
		counting = true;
	}
	cout<<"started\n";
	t.set_label(to_string(elapsedTime())+" seconds");
	draw_lines();
	cout<< "lines drawn\n";
	Fl::add_timeout(1.0, cb_update, this); // working
	cout<<"timeout added\n";
}

void timer::cb_update(void* data)
{
	cout<<"update\n";
	timer* ref = static_cast<timer*> (data);
	cout<<"static cast\n";
	ref->redraw();
	cout<<"redraw\n";
	if(ref->isRunning())
	{
		Fl::repeat_timeout(1.0,cb_update); // working
		cout<<"repeat timeout\n";
	}
}

void timer::redraw()
{
	draw_lines();
}

void timer::stop()
{
	if (counting)
	{
		end = clock();
		counting = false;
	}
}

unsigned long timer::elapsedTime() const
{
	if(isRunning())
		return ((unsigned long)clock() - begin) / CLOCKS_PER_SEC;
	else
		return (end-begin)/CLOCKS_PER_SEC;
}

bool timer::isRunning() const
{
	return counting;
}

void timer::draw_lines() const // something not working
{
	
	cout<<"Drawing lines\n";
	t.draw_lines();
	cout<<"done drawing\n";
}