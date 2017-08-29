#include "Third_window.h"

Third_window::Third_window(Point xy, int w, int h, Sixth_window* next_win, const string& title)
        :Window(xy,w,h,title),
        t1{Point{100,100},"Which level do you want?"},
        t2{Point{120,150},"(choose from 3-7)"},
        t{Point{300,100,},"grade"},
        difficulty_level(Point(200,200),100,20,"difficulty_level"),
        next_button3(Point(x_max()-100,y_max()-100),70,20,"next",cb_next3),
        next_button(Point(x_max()-250,200),70,20,"next",cb_next),
		win6(next_win)
{
	selector = new tileclick(50,50,80,100,50,50,this);
	t1.set_font_size(30);
	t1.set_color(Color::red);
	attach(t1);
	t2.set_font_size(30);
	t2.set_color(Color::red);
	attach(t2);
	attach(difficulty_level);
	attach(next_button);
}

void Third_window::cb_next3(Address, Address pw)
{
    reference_to<Third_window>(pw).next3();
}

void Third_window::next3() //dettach utems for replay and setup window 6
{
	if(selector->goodbuttons > selector->get_bottom().size()) //if not all buttons are used
	{
		cout<<"All tiles must be used\n";
		return; //wait for all buttons to be used
	}
	score = selector->get_total();
	savescore(difflevel);
	hide();
	detach(next_button3);
	selector->detach();
    attach(t1);
	attach(t2);
	attach(difficulty_level);
	attach(next_button);
    win6->show();
}

void Third_window::cb_next(Address,Address pw)
{
        reference_to<Third_window>(pw).next();
}

void Third_window::next() //set up game window
{
	difflevel = difficulty_level.get_int();
	if(difflevel>7||difflevel<3) //is level number valid
	{
		cout<<"Bad level argument\n";
		return; //wait for a valid number to be entered
	}
		
    detach(t1);
    detach(t2);
    detach(next_button);
    
	detach(difficulty_level);
    switch(difflevel)
    {
    	case(3):level3();
    	break;
    	case(4):level4();
    	break;
    	case(5):level5();
    	break;
    	case(6):level6();
    	break;
    	case(7):level7();
    	break;
    }

    redraw();
}

void Third_window::level3() //different function for each level
{
    attach(next_button3);
    vector<string>elements={"0","1","2","3","4","5","6","7","8","9","+","-","*","/"};
    int x1;
    int x2;
    int x3;
    while(true)
  {
    while(true)
    {
      srand (time(NULL));
      x1=rand() % 14; 
      x2=rand() % 14;
      x3=rand() % 14;
      if(x1==10||x1==11||x1==12||x1==13||x2==10||x2==11||x2==12||x2==13||x3==10||x3==11||x3==12||x3==13)
      break;
    }
    int sum=0;
    if(x1==10||x1==11||x1==12||x1==13)
      sum=sum+1;
    else;
    if(x2==10||x2==11||x2==12||x2==13)
      sum=sum+1;
    else;
    if(x3==10||x3==11||x3==12||x3==13)
      sum=sum+1;
    else;
    if(sum<2)
      break;
    else;
      
  }
  outputs={elements[x1],elements[x2],elements[x3]}; 
  selector->add_buttons(outputs); // send random number selected to tileclick :vector of buttons
}

void Third_window::level4()
{ 
    attach(next_button3);
    vector<string>elements={"0","1","2","3","4","5","6","7","8","9","+","-","*","/","!"};
    int x1;
    int x2;
    int x3;
	int x4;
    while(true)
  {
    while(true)
    {
      srand (time(NULL));
      x1=rand() % 15; 
      x2=rand() % 15;
      x3=rand() % 15;
      x4=rand() % 15;
      if(x1==10||x1==11||x1==12||x1==13||x1==14||x2==10||x2==11||x2==12||x2==13||x2==14||x3==10||x3==11||x3==12||x3==13||x3==14||x4==10||x4==11||x4==12||x4==13||x4==14)
      break;
      else;
    }
    int sum=0;
    if(x1==10||x1==11||x1==12||x1==13||x1==14)
      sum=sum+1;
    else;
    if(x2==10||x2==11||x2==12||x2==13||x2==14)
      sum=sum+1;
    else;
    if(x3==10||x3==11||x3==12||x3==13||x3==14)
      sum=sum+1;
    else;
    if(x4==10||x4==11||x4==12||x4==13||x4==14)
      sum=sum+1;
    else;
    if(sum<2)
      break;
    else;   
  }
    outputs={elements[x1],elements[x2],elements[x3],elements[x4]}; 
	selector->add_buttons(outputs);
}

void Third_window::level5()
{
    attach(next_button3);
    vector<string>elements={"0","1","2","3","4","5","6","7","8","9"}; //Generate three random numbers
    int x1;
    int x2;
    int x3;
    while(true)
    {
        srand (time(NULL));
        x1=rand() % 10; 
        x2=rand() % 10;
        x3=rand() % 10;
        break;        
    }
   vector<string>operators={"+","-","*","/","!","(",")"}; //Generate two random operators
   int x5;
   int x6;
   while (true)
   {
	    srand (time(NULL));
        x5=rand() % 7; 
        x6=rand() % 7;
		if ((x5==5&x6==6)||(x5==6&x6==5))
			break;
		else
			if (x5==5 & x6!=6)
				x6=6;
			else if (x6==5 & x5!=6)
				x5=6;
			else if (x6==6 & x5!=5)
				x5=5;
			else if (x5==6 & x6!=5)
				x6=5;
		break;
   }
  outputs={elements[x1],elements[x2],elements[x3],operators[x5],operators[x6]};
  selector->add_buttons(outputs); 
 }
   
void Third_window::level6()
{ 
    attach(next_button3);
    vector<string>elements={"0","1","2","3","4","5","6","7","8","9"}; //Generate four random numbers
    int x1;
    int x2;
    int x3;
    int x4;
    while(true)
    {
        srand (time(NULL));
        x1=rand() % 10; 
        x2=rand() % 10;
        x3=rand() % 10;
        x4=rand() % 10;
        break;        
    }
   vector<string>operators={"+","-","*","/","!","(",")"}; //Generate two random operators
   int x5;
   int x6;
   while (true)
   {
	    srand (time(NULL));
        x5=rand() % 7; 
        x6=rand() % 7;
		if ((x5==5&x6==6)||(x5==6&x6==5))
			break;
		else
			if (x5==5 & x6!=6)
				x6=6;
			else if (x6==5 & x5!=6)
				x5=6;
			else if (x6==6 & x5!=5)
				x5=5;
			else if (x5==6 & x6!=5)
				x6=5;
		break;
   }
  outputs={elements[x1],elements[x2],elements[x3],elements[x4],operators[x5],operators[x6]};
  selector->add_buttons(outputs); 
}

void Third_window::level7()
{ 
    attach(next_button3);
    vector<string>elements={"0","1","2","3","4","5","6","7","8","9"}; //Generate four random numbers
    int x1;
    int x2;
    int x3;
    int x4;
    while(true)
    {
        srand (time(NULL));
        x1=rand() % 10; 
        x2=rand() % 10;
        x3=rand() % 10;
        x4=rand() % 10;
        break;       
    }
   vector<string>operators={"+","-","*","/","!","(",")"}; //Generate three random operators
   int x5;
   int x6;
   int x7;
   while (true)
   {
	    srand (time(NULL));
        x5=rand() % 7; 
        x6=rand() % 7;
        x7=rand() % 7;
		if (((x5==5&(x6==6^x7==6))||(x6==5&(x5==6^x7==6))||(x7==5&(x6==6^x5==6)))||((x5==6&(x6==5^x7==5))||(x6==6&(x5==5^x7==5))||(x7==6&(x6==5^x5==5))))
			break;
		else
			if (x5==5 & x6!=6 & x7!=6)
				x6=6;
			else if (x6==5 & x5!=6 & x7!=6)
				x7=6;
			else if (x7==5 & x6!=6 & x5!=6)
				x5=6;
			else if (x5==6 & x6!=5 & x7!=5)
				x6=5;
			else if (x6==6 & x5!=5 & x7!=5)
				x7=5;
			else if (x7==6 & x6!=5 & x5!=5)
				x5=5;
		break;
   }
  outputs={elements[x1],elements[x2],elements[x3],elements[x4],operators[x5],operators[x6],operators[x7]};
  selector->add_buttons(outputs);  
}

void Third_window::savescore(int lvl) //save the score
{
	string filename = to_string(lvl); //get correct file
	filename+=".txt";
	try
	{
		ifstream ist {filename};
	
		vector<int>scores;
		vector<string>v;
		vector<string>grades(5);
		string s;
		while(ist.eof() == false) //get all scores out of file 
		{
		  getline(ist,s);
		  if (s != ""){
		  v.push_back(s);
		  }
		}
		ist.close();
		v.push_back(name+" "+score);
		for(int i=0;i<v.size();i++)//reads name and score
		{
			int score;
			string s;
			stringstream ss;
			ss<<v[i];
			ss >> s;
			ss >> score;
			scores.push_back(score);
		}	
		
		for(int i=0;i<scores.size();i++)//sort score
		{
			for(int j=0;j<scores.size()-i-1;j++)
			{
				if(scores[j]<scores[j+1])
				{
					int helper;
					helper=scores[j];
					scores[j]=scores[j+1];
					scores[j+1]=helper;
				}
			
			}
		}
		
		
		for(int i=0;i<v.size();i++)//put highest scores in another vector
		{
			int score;
			string s;
			stringstream ss;
			ss<<v[i];
			ss>>s;
			ss>>score;
			if(score==scores[0])
				grades[0]=v[i];
			else if(score==scores[1])
				grades[1]=v[i];
			else if(score==scores[2])
				grades[2]=v[i];
			else if(score==scores[3])
				grades[3]=v[i];
			else if(score==scores[4])
				grades[4]=v[i];
		}
		ofstream ost {filename};
		for(int i=0;i<grades.size();i++)
		{
			ost<<grades[i]<< "\n";
			ost.clear();
		}
		ost.close();
	}
	catch(exception&e)
	{
		cerr<<"error:"<<e.what()<<'\n';
	}
	catch(...)
	{
		cerr<<"Oops unknown exception!\n";
	}
}
