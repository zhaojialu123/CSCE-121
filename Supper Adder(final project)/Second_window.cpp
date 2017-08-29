#include "Second_window.h"

Second_window::Second_window(Point xy, int w, int h, Third_window* next_win, const string& title)
        :Window(xy,w,h,title),
        t1{Point{100,100},"what's your name?"},
        p1{Point{150,200},"picture1.jpeg"},
        p2{Point{330,120},"picture2.jpeg"},
        nickname(Point(100,200),100,20,"nickname:"),
        next_button1(Point(x_max()-580,300),70,20,"next",cb_next1),
        next_button2(Point(x_max()-100,y_max()-100),70,20,"next",cb_next2),
        quit_button(Point(x_max()-80,30),70,20,"quit",cb_quit),
		win3(next_win)
{
	t1.set_font_size(50);
	t1.set_color(Color::red);
	attach(t1);
	attach(p2);
	attach(nickname);
	attach(next_button1);
	attach(quit_button);
}

void Second_window::cb_quit(Address,Address pw)
{
    reference_to<Second_window>(pw).quit();
}

void Second_window::quit()
{
    hide();
}

void Second_window::cb_next1(Address,Address pw)
{
    reference_to<Second_window>(pw).next1();
}

void Second_window::next1()//get name and set up high score screen
{

    s = nickname.get_string();
	if (s == "") //check that name is entered
	{
		cout<<"please enter a name\n";
		return;
	}
	win3->name = s;
	Text* s1 = new Text{Point{50,50},"player:"};
	Text* s2 = new Text{Point{100,50},s};
	Text* s3 = new Text{Point{200,70},"Top scores"};
	Text* s4 = new Text{Point{50,85},"level 3:"};
	Text* s5 = new Text{Point{150,85},"level 4:"};
	Text* s6 = new Text{Point{250,85},"level 5:"};
	Text* s7 = new Text{Point{350,85},"level 6:"};
	Text* s8 = new Text{Point{450,85},"level 7:"};
    initials.push_back(s1);
    initials.push_back(s2);
    initials.push_back(s3);
    initials.push_back(s4);
    initials.push_back(s5);
    initials.push_back(s6);
    initials.push_back(s7);
    initials.push_back(s8);
    ifstream ist3 {"3.txt"};
    for(int i=0;i<5;i++) //get all scores from files;
    {
        string s1;
        getline(ist3,s1);
		Text* s =  new Text(Point{50,100+15*i},s1);
        scores3.push_back(s);
		ist3.clear();
    }
	ist3.close();
    ifstream ist4 {"4.txt"};
    for(int i=0;i<5;i++)
    {
        string s1;
        getline(ist4,s1);
		Text* s =  new Text(Point{150,100+15*i},s1);
        scores4.push_back(s);
		ist4.clear();
    }
	ist4.close();
    ifstream ist5 {"5.txt"};
	int i = 0;
	for (string line; getline(ist5, line); )
    {
		Text* s =  new Text(Point{250,100+15*i},line);
		scores5.push_back(s);
		++i;
    }
	ist5.close();
    ifstream ist6 {"6.txt"};
    for(int i=0;i<5;i++)
    {
        string s1;
        getline(ist6,s1);
		Text* s = new Text(Point{350,100+15*i},s1);
        scores6.push_back(s);
		ist6.clear();
    }
	ist6.close();
    ifstream ist7 {"7.txt"};
    for(int i=0;i<5;i++)
    {
        string s1;
        getline(ist7,s1);
		Text* s =  new Text(Point{450,100+15*i},s1);
        scores7.push_back(s);
		ist7.clear();

    }
	ist7.close();
    detach(t1);
    detach(next_button1);
    detach(nickname);
    detach(p2);
    attach(p1);
    for(int a=0;a<8;a++) //attach all scores on screen
    {
        attach(*initials[a]);
    }
    for(int j=0;j<5;j++)
    {
     attach(*scores3[j]);
    }
    for(int j=0;j<5;j++)
    {
     attach(*scores4[j]);
    }
    for(int j=0;j<5;j++)
    {
     attach(*scores5[j]);
    }
    for(int j=0;j<5;j++)
    {
     attach(*scores6[j]);
    }
    for(int j=0;j<5;j++)
    {
     attach(*scores7[j]);
    }
    attach(next_button2);
    redraw();

}

void Second_window::cb_next2(Address,Address pw)
{
        reference_to<Second_window>(pw).next2();
}

void Second_window::next2()//dettach everything for replay and open window 3
{
    for(int a=0;a<7;a++)
    {
        detach(*initials[a]);
    }
    for(int j=0;j<5;j++)
    {
        detach(*scores3[j]);
    }
    for(int j=0;j<5;j++)
    {
        detach(*scores4[j]);
    }
    for(int j=0;j<5;j++)
    {
        detach(*scores5[j]);
    }
    for(int j=0;j<5;j++)
    {
        detach(*scores6[j]);
    }
    for(int j=0;j<5;j++)
    {
        detach(*scores7[j]);
    }
	initials.clear();
	scores3.clear();
	scores4.clear();
	scores5.clear();
	scores6.clear();
	scores7.clear();
    detach(p1);
	detach(next_button2);
	attach(t1);
	attach(p2);
	attach(nickname);
	attach(next_button1);
	attach(quit_button);
    hide();
	win3->show();
}