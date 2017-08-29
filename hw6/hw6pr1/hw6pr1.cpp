//Jialu Zhao
//CSCE 121-508
//Due: October 25, 2016
//hw6pr1.cpp
#include"Graph.h"
#include"Simple_window.h"
using namespace Graph_lib;
int main()
    {	
    try{
        Point tl(150,150);
        Simple_window win(tl,640,640,"My window");//create windows
        Vector_ref<Rectangle>vr;//create a vector which have several rectangles
        for(int i=0;i<8;++i)
        {
            if(i%2==0)
            {
                for(int j=0;j<8;++j)
                    if(j%2==1)
                {
                    vr.push_back(new Rectangle{Point{i*80,j*80},80,80});
                    vr[vr.size()-1].set_fill_color(Color{2});//color 2 is green which is light color
                    win.attach(vr[vr.size()-1]);
                }
                else
                {
                    vr.push_back(new Rectangle{Point{i*80,j*80},80,80});
                    vr[vr.size()-1].set_fill_color(Color{1});//color 1 is red
                    win.attach(vr[vr.size()-1]);
                }
            }
            else
            {
                for(int j=0;j<8;++j)
                    if(j%2==1)
                {
                    vr.push_back(new Rectangle{Point{i*80,j*80},80,80});
                    vr[vr.size()-1].set_fill_color(Color{1});
                    win.attach(vr[vr.size()-1]);
                }
                else
                {
                    vr.push_back(new Rectangle{Point{i*80,j*80},80,80});
                    vr[vr.size()-1].set_fill_color(Color{2});
                    win.attach(vr[vr.size()-1]);
                }
            }
            }
        win.wait_for_button();
        return 0;
    }
    catch(exception&e){//catch exception
        cerr<<"error:"<<e.what()<<'\n';
        return 1;
    }
    catch(...){
        cerr<<"Oops:unknown exception!\n";
        return 2;
    }
}