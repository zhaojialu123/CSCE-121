#include "std_lib_facilities_4.h"
#include <time.h>
#include "GUI.h"
#include <thread>
#include <chrono>

using namespace Graph_lib;

struct timer : Shape
{
public:
	timer(Point pp);
	void start();
	void stop();
	unsigned long elapsedTime() const;
	bool isRunning() const;
	Point p;

private:
	unsigned long begin;
	unsigned long end;
	void redraw();
	bool counting;
	void draw_lines() const;
	static void cb_update(void*);
	Text t;
};