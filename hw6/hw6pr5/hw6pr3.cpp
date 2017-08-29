#include"Graph.h"
#include"Simple_window.h"
using namespace Graph_lib;
    class  Scandinavian_flag
    {
        Color m_color1;
        Color m_color2;
        public:
        Scandinavian_flag(Color color1,Color color2):m_color1(color1),m_color2(color2){}
        void flag()
        {   
            Point tl(150,150);
	        Simple_window win(tl,600,400,"My window");
            Rectangle rect1{Point{0,0},120,100};
            Rectangle rect2{Point{200,0},300,100};
            Rectangle rect3{Point{0,180},120,120};
            Rectangle rect4{Point{200,180},300,120};
            win.attach(rect1);
            win.attach(rect2);
            win.attach(rect3);
            win.attach(rect4);
            Graph_lib::Polygon poly;
            poly.add(Point(120,0));
            poly.add(Point(200,0));
            poly.add(Point(200,100));
            poly.add(Point(500,100));
            poly.add(Point(500,180));
            poly.add(Point(200,180));
            poly.add(Point(200,300));
            poly.add(Point(120,300));
            poly.add(Point(120,180));
            poly.add(Point(0,180));
            poly.add(Point(0,100));
            poly.add(Point(120,100));
            win.attach(poly);
            rect1.set_fill_color(m_color2);
            rect2.set_fill_color(m_color2);
            rect3.set_fill_color(m_color2);
            rect4.set_fill_color(m_color2);
            poly.set_fill_color(m_color1);
            Text t{Point{350,350},"Sweden"};
            string finland = "Finland";
            string denmark = "Denmark";
                if(m_color1.as_int()==Color::blue){
                    t.set_label(finland);
                }
                else if(m_color1.as_int()==Color::white){
                    t.set_label(denmark);
                }
            
            win.attach(t);

            win.wait_for_button();
            //loops through all shapes attached to win and draws them
        }


    };
        
int main()
{
    Scandinavian_flag Denmark(Color::white,Color::red);
    Denmark.flag();
    Scandinavian_flag Finland(Color::blue,Color::white);
    Finland.flag();
    Scandinavian_flag Sweden(Color::yellow,Color::blue);
    Sweden.flag();

    
}



