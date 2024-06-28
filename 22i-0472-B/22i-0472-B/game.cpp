#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <unistd.h>
#include<SFML/Audio.hpp>
//#include <SFML/System.hpp>
using namespace std;
using namespace sf;



int hmmatch(int arr[5][5], int &leo, int &cam, int &ele, int &cre, int &lamp, int &deer, int &gir, int &score)
{

	srand(time(0));
	int rad;
	
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
		{
		
			if ( (arr[i+2][j]==arr[i][j] ) && (arr[i+1][j]==arr[i][j]) ) 	
			{
				if(arr[i][j]==0)
				{
					score+=3;
					cam++;					
				}
				else if(arr[i][j]==1)
				{
					score+=4;
					ele++;				
				}
				else if(arr[i][j]==2)
				{
					score+=2;
					cre++;					
				}
				else if(arr[i][j]==3)
				{
					score+=5;
					deer++;					
				}
				else if(arr[i][j]==4)
				{
					score+=1;
					gir++;				
				}
				else if(arr[i][j]==5)
				{
					score+=6;
					leo++;					
				}
				
				rad = rand()%6;	
				arr[i+2][j]=rad;
				rad = rand()%6;	
				arr[i][j]=rad;
				rad = rand()%6;	
				arr[i+1][j]=rad;
				//cout<<"in if 3"<<endl;
				
				if( arr[i+3][j]==arr[i][j] )
				{
					score+=3;
					rad = rand()%6;
					arr[i+3][j]=rad;
					cout<<"inii+3"<<endl;
				
				if(arr[i+4][j]==arr[i][j])
				{
					score+=4;
					rad = rand()%6;
					arr[i+4][j]=rad;
				
				if(arr[i+5][j]==arr[i][j])
				{
					score+=5;
					rad = rand()%6;
					arr[i+5][j]=rad;
				}

				}
				
				}
				
				
			}
			
			else if ( (arr[i][j+2]==arr[i][j] ) && (arr[i][j+1]==arr[i][j]) ) 	
			{
				if(arr[i][j]==0)
				{
					score+=3;
					cam++;					
				}
				else if(arr[i][j]==1)
				{
					score+=4;
					ele++;				
				}
				else if(arr[i][j]==2)
				{
					score+=2;
					cre++;					
				}
				else if(arr[i][j]==3)
				{
					score+=5;
					deer++;					
				}
				else if(arr[i][j]==4)
				{
					score+=1;
					gir++;				
				}
				else if(arr[i][j]==5)
				{
					score+=6;
					leo++;
				}
				
				cout<<leo<<endl;
				rad = rand()%6;
				arr[i][j+2]=rad;
				rad = rand()%6;	
				arr[i][j]=rad;
				rad = rand()%6;	
				arr[i][j+1]=rad;
				//cout<<"in if 6"<<endl;	
				
				if(arr[i][j+3]==arr[i][j])
				{
					score+=3;
					rad = rand()%6;
					arr[i][j+3]=rad;
					cout<<"injjj+3"<<endl;
				
				if(arr[i][j+4]==arr[i][j])
				{
					score+=4;
					rad = rand()%6;
					arr[i][j+4]=rad;
				
				if(arr[i][j+5]==arr[i][j])
				{
					score+=5;
					rad = rand()%6;
					arr[i][j+5]=rad;
				}
				
				}

				}
			}
			
			
		
		}
			
			return score;
} 



int main()
{
int ts = 54; //tile size

int x=0,y=0,rad;

int js=58;

int seconds = 60;

int count=0,check=0,click=0;

int leo=0,gir=0,lamp=0,cre=0,deer=0,ele=0, cam=0 ;

 int appcheck=0, appwindow=0;
 
 int score=0;

Vector2i offset(58,24);  
    srand(time(0));
    RenderWindow app(VideoMode(740,480), "Menagerie");
    app.setFramerateLimit(60);
    
    Texture t1,t2,t3[7];
  
    t1.loadFromFile("sprites/background.png");
    t2.loadFromFile("sprites/gems.png");
    
    t3[0].loadFromFile("sprites/camel.png");
    t3[1].loadFromFile("sprites/elephant.png");
    t3[2].loadFromFile("sprites/creature.png");
    t3[3].loadFromFile("sprites/deer.png");
    t3[4].loadFromFile("sprites/lepord.png");
    t3[5].loadFromFile("sprites/girafe.png");
    
    Sprite background(t1), gems(t2);// grid[9][11];
    int grid[5][5];
   
    	
    	for(int i=0 ; i<5 ;i++)
    	{
    		for(int j=0;j<5;j++)
    		{
    			rad=rand()%6; 
    		//	Sprite f(t3[rad]);
    		//	grid[i][j]=f; 
    			grid[i][j]=rad;
    		}
				    	
    	}



    Event e;
    
    int x1,y1,x2,y2,k=0;
    int  posx,posy;
    Vector2i pos;
    int temp, move=25,sco=0;
    
    //score 
  /*
    */
    string string_score;
    string_score = to_string(score);
    
    Font scoreimg;
   
  //  scoreimg.loadFromFile("PinkAcapella.otf");
 //   scoreimg.loadFromFile("Webcomic.ttf");
//   scoreimg.loadFromFile("Christmas Lollipop.otf");
   scoreimg.loadFromFile("Berliner_Wand.ttf");
    
    Text text;
    
    text.setFont( scoreimg );
    text.setString( "Score : " );
    text.setPosition(Vector2f(600,10));
    text.setCharacterSize( 30 );
    text.setFillColor( Color::Red );
  //  text.setStyle( Text::Style::Underlined );
    text.setOutlineColor( Color::Yellow );
    text.setOutlineThickness( 1 ); 
    
    Text tscore;
    tscore.setFont(scoreimg);
    tscore.setString(string_score);
    tscore.setPosition(Vector2f(700,10));
    tscore.setCharacterSize( 30 );
 	
    // animal text
    Text name1;
    name1.setFont(scoreimg);
    name1.setString("Rabbit");
    name1.setPosition(Vector2f(480,120));
    name1.setCharacterSize( 30 );
    name1.setFillColor( Color::Red );
    name1.setOutlineColor( Color::Yellow );
    name1.setOutlineThickness( 1 ); 
    
    Text name2;
    name2.setFont(scoreimg);
    name2.setString("Racoon");
    name2.setPosition(Vector2f(480,180));
    name2.setCharacterSize( 30 );
    name2.setFillColor( Color::Red );
    name2.setOutlineColor( Color::Yellow );
    name2.setOutlineThickness( 1 ); 
    
    Text name3;
    name3.setFont(scoreimg);
    name3.setString("Piggy");
    name3.setPosition(Vector2f(480,240));
    name3.setCharacterSize( 30 );
    name3.setFillColor( Color::Red );
    name3.setOutlineColor( Color::Yellow );
    name3.setOutlineThickness( 1 ); 
    
    Text name4;
    name4.setFont(scoreimg);
    name4.setString("Cow");
    name4.setPosition(Vector2f(480,300));
    name4.setCharacterSize( 30 );
    name4.setFillColor( Color::Red );
    name4.setOutlineColor( Color::Yellow );
    name4.setOutlineThickness( 1 ); 
    
    Text name5;
    name5.setFont(scoreimg);
    name5.setString("Bear");
    name5.setPosition(Vector2f(480,360));
    name5.setCharacterSize( 30 );
    name5.setFillColor( Color::Red );
    name5.setOutlineColor( Color::Yellow );
    name5.setOutlineThickness( 1 ); 
    
    Text name6;
    name6.setFont(scoreimg);
    name6.setString("Koala");
    name6.setPosition(Vector2f(480,420));
    name6.setCharacterSize( 30 );
    name6.setFillColor( Color::Red );
    name6.setOutlineColor( Color::Yellow );
    name6.setOutlineThickness( 1 ); 
 
    
    //Frame
    RectangleShape frame;
    frame.setPosition(Vector2f(0,0));
    frame.setSize(Vector2f(280.f, 284.f));
    frame.setOutlineThickness(0.f);
    frame.setOutlineColor(Color::Green);
    frame.setFillColor(Color::Transparent);
    
    //animal bar
    
    //leopord
    RectangleShape leooutbar;
    leooutbar.setPosition(Vector2f(570,120));
    leooutbar.setSize(Vector2f(130.f, 30.f));
    leooutbar.setOutlineThickness(4.f);
    leooutbar.setOutlineColor(Color::Yellow);
    leooutbar.setFillColor(Color::Black);
    
    RectangleShape leoinbar1;
    leoinbar1.setPosition(Vector2f(570,120));
    leoinbar1.setFillColor(Color::Red);
    leoinbar1.setSize(Vector2f(50.f,30.f));
 	
     RectangleShape leoinbar2;
    leoinbar2.setPosition(Vector2f(620,120));
    leoinbar2.setFillColor(Color::Red);
    leoinbar2.setSize(Vector2f(50.f,30.f));
    
    RectangleShape leoinbar3;
    leoinbar3.setPosition(Vector2f(650,120));
    leoinbar3.setFillColor(Color::Red);
    leoinbar3.setSize(Vector2f(50.f,30.f));
    
    //deer
    RectangleShape deeroutbar;
    deeroutbar.setPosition(Vector2f(570,180));
    deeroutbar.setSize(Vector2f(130.f, 30.f));
    deeroutbar.setOutlineThickness(4.f);
    deeroutbar.setOutlineColor(Color::Yellow);
    deeroutbar.setFillColor(Color::Black);
    
    RectangleShape deerinbar1;
    deerinbar1.setPosition(Vector2f(570,180));
    deerinbar1.setFillColor(Color::Red);
    deerinbar1.setSize(Vector2f(50.f,30.f));
 	
     RectangleShape deerinbar2;
    deerinbar2.setPosition(Vector2f(620,180));
    deerinbar2.setFillColor(Color::Red);
    deerinbar2.setSize(Vector2f(50.f,30.f));
    
    RectangleShape deerinbar3;
    deerinbar3.setPosition(Vector2f(650,180));
    deerinbar3.setFillColor(Color::Red);
    deerinbar3.setSize(Vector2f(50.f,30.f));
    
    //creature
    RectangleShape creoutbar;
    creoutbar.setPosition(Vector2f(570,240));
    creoutbar.setSize(Vector2f(130.f, 30.f));
    creoutbar.setOutlineThickness(4.f);
    creoutbar.setOutlineColor(Color::Yellow);
    creoutbar.setFillColor(Color::Black);
    
    RectangleShape creinbar1;
    creinbar1.setPosition(Vector2f(570,240));
    creinbar1.setFillColor(Color::Red);
    creinbar1.setSize(Vector2f(50.f,30.f));
 	
     RectangleShape creinbar2;
    creinbar2.setPosition(Vector2f(620,240));
    creinbar2.setFillColor(Color::Red);
    creinbar2.setSize(Vector2f(50.f,30.f));
    
    RectangleShape creinbar3;
    creinbar3.setPosition(Vector2f(650,240));
    creinbar3.setFillColor(Color::Red);
    creinbar3.setSize(Vector2f(50.f,30.f));
    
    //Girafe
    RectangleShape giroutbar;
    giroutbar.setPosition(Vector2f(570,300));
    giroutbar.setSize(Vector2f(130.f, 30.f));
    giroutbar.setOutlineThickness(4.f);
    giroutbar.setOutlineColor(Color::Yellow);
    giroutbar.setFillColor(Color::Black);
    
    RectangleShape girinbar1;
    girinbar1.setPosition(Vector2f(570,300));
    girinbar1.setFillColor(Color::Red);
    girinbar1.setSize(Vector2f(50.f,30.f));
 	
     RectangleShape girinbar2;
    girinbar2.setPosition(Vector2f(620,300));
    girinbar2.setFillColor(Color::Red);
    girinbar2.setSize(Vector2f(50.f,30.f));
    
    RectangleShape girinbar3;
    girinbar3.setPosition(Vector2f(650,300));
    girinbar3.setFillColor(Color::Red);
    girinbar3.setSize(Vector2f(50.f,30.f));
    
    //elepahant
    RectangleShape eleoutbar;
    eleoutbar.setPosition(Vector2f(570,360));
    eleoutbar.setSize(Vector2f(130.f, 30.f));
    eleoutbar.setOutlineThickness(4.f);
    eleoutbar.setOutlineColor(Color::Yellow);
    eleoutbar.setFillColor(Color::Black);
    
    RectangleShape eleinbar1;
    eleinbar1.setPosition(Vector2f(570,360));
    eleinbar1.setFillColor(Color::Red);
    eleinbar1.setSize(Vector2f(50.f,30.f));
 	
     RectangleShape eleinbar2;
    eleinbar2.setPosition(Vector2f(620,360));
    eleinbar2.setFillColor(Color::Red);
    eleinbar2.setSize(Vector2f(50.f,30.f));
    
    RectangleShape eleinbar3;
    eleinbar3.setPosition(Vector2f(650,360));
    eleinbar3.setFillColor(Color::Red);
    eleinbar3.setSize(Vector2f(50.f,30.f));
    
    //camel
    RectangleShape camoutbar;
    camoutbar.setPosition(Vector2f(570,420));
    camoutbar.setSize(Vector2f(130.f, 30.f));
    camoutbar.setOutlineThickness(4.f);
    camoutbar.setOutlineColor(Color::Yellow);
    camoutbar.setFillColor(Color::Black);
    
    RectangleShape caminbar1;
    caminbar1.setPosition(Vector2f(570,420));
    caminbar1.setFillColor(Color::Red);
    caminbar1.setSize(Vector2f(50.f,30.f));
 	
     RectangleShape caminbar2;
    caminbar2.setPosition(Vector2f(620,420));
    caminbar2.setFillColor(Color::Red);
    caminbar2.setSize(Vector2f(50.f,30.f));
    
    RectangleShape caminbar3;
    caminbar3.setPosition(Vector2f(650,420));
    caminbar3.setFillColor(Color::Red);
    caminbar3.setSize(Vector2f(50.f,30.f));
    
    
    //lamp
    RectangleShape lampoutbar;
    lampoutbar.setPosition(Vector2f(570,480));
    lampoutbar.setSize(Vector2f(130.f, 30.f));
    lampoutbar.setOutlineThickness(4.f);
    lampoutbar.setOutlineColor(Color::Yellow);
    lampoutbar.setFillColor(Color::Black);
    
    RectangleShape lampinbar1;
    lampinbar1.setPosition(Vector2f(570,480));
    lampinbar1.setFillColor(Color::Red);
    lampinbar1.setSize(Vector2f(50.f,30.f));
 	
     RectangleShape lampinbar2;
    lampinbar2.setPosition(Vector2f(620,480));
    lampinbar2.setFillColor(Color::Red);
    lampinbar2.setSize(Vector2f(50.f,30.f));
    
    RectangleShape lampinbar3;
    lampinbar3.setPosition(Vector2f(650,480));
    lampinbar3.setFillColor(Color::Red);
    lampinbar3.setSize(Vector2f(50.f,30.f));
    
    //background
    Texture back;
    back.loadFromFile("leaves2.jpeg");
    
    RectangleShape backgrund;
    backgrund.setSize(Vector2f(450.f, 187.f));
    backgrund.setPosition(0, 284);
    backgrund.setOutlineThickness(0.f);
    backgrund.setOutlineColor(Color::Green);
    backgrund.setTexture(&back);
    
    Texture back2;
    back2.loadFromFile("leaves.jpeg");
    
    RectangleShape backgrund2;
    backgrund2.setSize(Vector2f(168.f, 287.f));
    backgrund2.setPosition(282, 0);
    backgrund2.setOutlineThickness(0.f);
    backgrund2.setOutlineColor(Color::Green);
    backgrund2.setTexture(&back2);
   
   //Moves
   
    string string_moves;
    string_moves = to_string(move);
   
    Text moves;
    
    moves.setFont( scoreimg );
    moves.setString( "Move's left : " );
    moves.setPosition(Vector2f(570,50));
    moves.setCharacterSize( 30 );
    moves.setFillColor( Color::Red );
  //  text.setStyle( Text::Style::Underlined );
    moves.setOutlineColor( Color::Yellow );
    moves.setOutlineThickness( 1 );
    
    Text movesnum;
    
    movesnum.setFont(scoreimg);
    movesnum.setString(string_moves);
    movesnum.setPosition(Vector2f(700,50));
    movesnum.setCharacterSize( 30 );
    
      int tempmoves=0, ans_x=0, ans_y=0, temptime=0;
      
      
      //timer
      Clock clock;
      
      Font berliner;
      berliner.loadFromFile("Berliner_Wand.ttf");
      
     Text tim;
     tim.setFont(berliner);
     tim.setPosition(490,50);
     tim.setCharacterSize(40);
     tim.setFillColor(Color::Red);
 //    tim.setOutlineColor(Color::Yellow);
   //  tim.setOutlineThickness(1);
   clock.restart();
   Time elapsed0 = clock.getElapsedTime( );
   
      cout<<elapsed0.asSeconds()<<endl;
      
      
 
   
   
   //music
   sf::Music music;
   music.openFromFile("jungle.ogg");
   
   music.play();
    
    //menu
    Texture menu1;
    menu1.loadFromFile("game_menu.png");
    
    Sprite game_menu(menu1);
    
    //menu sprites
    
    Texture box1;
    box1.loadFromFile("normal.png");
    
    Sprite normalmode(box1);
    normalmode.setPosition(174,69);
    
    Texture box2;
    box2.loadFromFile("tt.png");
    
    Sprite ttmode(box2);
    ttmode.setPosition(163,170);
    
    Texture box3;
    box3.loadFromFile("help.png");
    
    Sprite helpmode(box3);
    helpmode.setPosition(166,276);
    
    int no_in=0;
    
    //End game
    Texture w;
    w.loadFromFile("sprites/youwon.jpeg");
    
    Sprite win(w);
    
    Texture l;
    l.loadFromFile("sprites/youlost.jpeg");
    
    Sprite lost(l);
    
    //background new
    Texture bg;
    bg.loadFromFile("junglebackground.jpeg");
    
    Sprite backus(bg);
    backus.setScale(Vector2f(2.1,3.3));
    
    //black sq
    
  /*  RectangleShape bs;
    bs.setPosition(Vector2f(490,52));
    bs.setSize(Vector2f(50.f, 40.f));
    bs.setFillColor(Color::Black);*/
    
    Texture help;
    help.loadFromFile("sprites/helpmenu.png");
    Sprite helpmenu(help);
    
    
    while (app.isOpen()){
    while (app.pollEvent(e)){
    if (e.type == Event::Closed)
                app.close();
                if (e.type == Event::MouseButtonPressed)
                if (e.key.code == Mouse::Left){
       
      		click++;
      		pos= Mouse::getPosition(app);
      		posx = (Mouse::getPosition(app)).x;
      		posy = (Mouse::getPosition(app)).y;
      		
      		//cout<< Mouse::getPosition(app).x<<endl;
       		cout<<pos.x<<" "<< pos.y<<endl;
       
                }
                }  
     
       
       
   Time elapsed1 = clock.getElapsedTime( );
   //cout<<elapsed1.asSeconds()<<endl;
       tim.setString( to_string( 45 -  ( int )( clock.getElapsedTime() ).asMilliseconds()/1000) );
       
  
   
    
    string_moves = to_string(move);
   movesnum.setFont(scoreimg);
    movesnum.setString(string_moves);
    movesnum.setPosition(Vector2f(700,50));
    movesnum.setCharacterSize( 30 ); 
    movesnum.setFillColor( Color::White);
     
	
	
       
    
                
 /* if(tempmoves>move)
  {
  movesnum.setFillColor(Color::Black);
  movesnum.setOutlineColor(Color::Black);
   app.draw(movesnum);
   }*/
                
        

	
//menu page




if(appcheck==0)
{
if(click==1)
{

ans_x = (Mouse::getPosition(app)).x;
ans_y = (Mouse::getPosition(app)).y;
}

while( ( (ans_x>=177 && ans_x<=514) && (ans_y>=99 && ans_y <= 140) && no_in==0 ) && appcheck!=1 )
{
appcheck=1;
no_in++;
}

while( ( (ans_x>=162 && ans_x<=521) && (ans_y>=195 && ans_y <= 235) && no_in==0 ) && appcheck!=2 )
{
appcheck=2;
no_in++;
}


while( ( (ans_x>=162 && ans_x<=521) && (ans_y>=285 && ans_y <= 325) && no_in==0 ) && appcheck!=3 )
{
appcheck=3;
no_in++;
}

}

if(appcheck==0 && no_in==0)
{
//app.draw(backus);
app.draw(game_menu);
app.draw(normalmode);
app.draw(ttmode);
app.draw(helpmode);

app.display();

}


if( (appcheck==1 || appcheck==2 ) && no_in==1)
{
no_in++;
app.clear();
click=0;
 app.draw(backus);
}      


else if(no_in==2)
{
app.clear();
app.draw(backus);
app.display();
no_in=3;
}	


//normal mode 
if(appcheck==1)               
{
if( move && (gir<=3 || cre <= 3 || deer <= 3 || leo <= 3 || ele <= 3 || cam <= 3))
//if(move)
{
  

   
   
   //mouse click left
   if(click==1)
   {
   	x1=pos.x/58;
   	y1=pos.y/58;
   }
   
   if(click==2)
   {
   	x2=pos.x/58;
   	y2=pos.y/58;
   	
	 //if( abs(x2-x1)+abs(y2-y1)==1 )
  	 if( (abs(x1-x2)+abs(y1-y2)) ==1 )
         {
         //	cout<<grid[y1][x1]<<" "<< grid[y2][x2]<<endl;
         	temp=grid[y1][x1];
         	grid[y1][x1]=grid[y2][x2];
         	grid[y2][x2]=temp;
         	//cout<<grid[y1][x1]<<" "<< grid[y2][x2]<<endl;
   		click=0;
   		
   		cout<<score<<endl;
   		
   		
  	 } 
  	 
  
         
         else
         {
         	click=1;
         }
         
         move--;
                
   }
   
   
   //second swap
 /*  string_score="";
  tscore.setString(string_score); */
  
    string_score = to_string(score);
   tscore.setFont(scoreimg);
    tscore.setString(string_score);
    tscore.setPosition(Vector2f(700,10));
    tscore.setCharacterSize( 30 ); 
     tscore.setFillColor( Color::White); 
     
     int tempscore=score;
     
   hmmatch(grid, leo, cam, ele, cre, lamp, deer, gir, score);
   
  if(tempscore<score)
  {
  tscore.setFillColor(Color::Black);
  tscore.setOutlineColor(Color::Black);
//  tscore.setFillColor( Color::Transparent );
   }
   app.draw(tscore);
  
  
  if(move==0 || (gir >=3 && cre >= 3 && deer >= 3 && leo >= 3 && ele >= 3 && cam >= 3) )
  {
  appcheck=4;
	
	
  }
  
  //cout<<"tm:"<<tempmoves<<"\nm:"<<move<<endl;

 
 
   
  if(tempmoves>move)
  {
  
  movesnum.setFillColor(Color::Black);
  movesnum.setOutlineColor(Color::Black);
   }
  app.draw(movesnum);
   
   
   
  
  
 tempmoves=move;
 
 
 
 /*
   for(int i=0 ; i<5 ;i++)
    {
  
    	for(int j=0;j<5 ;j++)
    	{
    	cout<<grid[i][j]<<" ";
    	}
    	
    	cout<<endl;
   
   }
 */
 
   
   
  
   
  
   for(int i=0 ; i<5 ;i++)
    {
  
    	for(int j=0;j<5 ;j++)
    	{
    	
    		if(grid[i][j]==0 && (k>=0  && k<=4))
    		{
    			//t3[0].loadFromFile("sprites/camel.png");
    			//t3[0].loadFromFile("sprites/oink.jpeg");
    			t3[0].loadFromFile("sprites/kowala.png");
    		}
    		
    		else if(grid[i][j]==1 && (k>=0  && k<=4))
    		{
    			//t3[0].loadFromFile("sprites/elephant.png");
    			//t3[0].loadFromFile("sprites/monk.jpeg");
    			t3[0].loadFromFile("sprites/bear.png");
    
    		}
    		
    		else if(grid[i][j]==2 && (k>=0  && k<=4) ) 
    		{
    			//t3[0].loadFromFile("sprites/creature.png");
    			//t3[0].loadFromFile("sprites/racoon.jpeg");
    			t3[0].loadFromFile("sprites/oinky.png");
    			
    		}
    		
    		else if(grid[i][j]==3 && (k>=0  && k<=4) )
    		{
    			t3[0].loadFromFile("sprites/racooon.png");
    			//t3[0].loadFromFile("sprites/sheep.jpeg");
    		}
    		
    		else if(grid[i][j]==4 && (k>=0  && k<=4) )
    		{
    			t3[0].loadFromFile("sprites/coww.png");
    			//t3[0].loadFromFile("sprites/rabbit.jpeg");
    		}
    		
    		else if(grid[i][j]==5 && (k>=0  && k<=4) )
    		{
    			//t3[0].loadFromFile("sprites/lepord.png");
    			t3[0].loadFromFile("sprites/rabbitt.png");
    		}
    		
    		
   
    		Sprite f(t3[0]);
    		f.setPosition(Vector2f (x,y) );
    		
    		//if(x<400)
    		//x+=58;
    		x+=js;
   	 	app.draw(f);
  	  	app.display();
    	}
    	
    	//if(y<=358)
    	{
    		//y+=58;
    		y+=js;
    		x=0;
    	}
    	
    	
    
    }
    
    //in game draws
    
      app.draw( text );
   // app.draw( lblscore );
 
    app.draw(tscore);
    app.draw(moves);
    app.draw(movesnum);
    
    app.draw(leooutbar);
    app.draw(camoutbar);
    app.draw(eleoutbar);
    app.draw(creoutbar);
    app.draw(deeroutbar);
    //app.draw(lampoutbar);
    app.draw(giroutbar);
    
   // app.draw(tim);
    
    
     if(leo>=1)
     {
    app.draw(leoinbar1);
     if(leo>=2)
     {
    app.draw(leoinbar2);
    	if(leo>=3)
    app.draw(leoinbar3);
     }  
     }
     
      if(cam>=1)
     {
    app.draw(caminbar1);
     if(cam>=2)
     {
    app.draw(caminbar2);
    	if(cam>=3)
    app.draw(caminbar3);
     }  
     }
     
      if(ele>=1)
     {
    app.draw(eleinbar1);
     if(ele>=2)
     {
    app.draw(eleinbar2);
    	if(ele>=3)
    app.draw(eleinbar3);
     }  
     }
     
      if(cre>=1)
     {
    app.draw(creinbar1);
     if(cre>=2)
     {
    app.draw(creinbar2);
    	if(cre>=3)
    app.draw(creinbar3);
     }  
     }
     
      if(lamp>=1)
     {
    app.draw(lampinbar1);
     if(lamp>=2)
     {
    app.draw(lampinbar2);
    	if(lamp>=3)
    app.draw(lampinbar3);
     }  
     }
     
      if(deer>=1)
     {
    app.draw(deerinbar1);
     if(deer>=2)
     {
    app.draw(deerinbar2);
    	if(deer>=3)
    app.draw(deerinbar3);
     }  
     }
     
     if(gir>=1)
     {
    app.draw(girinbar1);
     if(gir>=2)
     {
    app.draw(girinbar2);
    	if(gir>=3)
    app.draw(girinbar3);
     }  
     }
     
     
   app.draw(frame);  
   app.draw(name1);
   app.draw(name2);
   app.draw(name3);
   app.draw(name4);
   app.draw(name5);
   app.draw(name6);
   
   //app.draw(name6);
 //  app.draw(timer);
   //app.draw(timenum);
  // app.draw(timer);
   
   
    	//	app.draw(backgrund);
    		
    	//	app.draw(backgrund2);
   
    app.display();
//  app.draw(bs);
  
  //app.display();  
    
}

}




else if(appcheck==2)
{

if( move || (gir >=3 && cre >= 3 && deer >= 3 && leo >= 3 && ele >= 3 && cam >= 3)  ) 


 tim.setFillColor(Color::Red);
    // tim.setOutlineColor(Color::Yellow);
    // tim.setOutlineThickness(1);
  
       app.draw(tim);
       app.display();
       
       tim.setFillColor(Color::Black);
      // tim.setOutlineColor(Color::Black);
    // tim.setOutlineThickness(0);
       app.draw(tim);
    //   app.display(); 

   
   
   //mouse click left
   if(click==1)
   {
   	x1=pos.x/58;
   	y1=pos.y/58;
   }
   
   if(click==2)
   {
   	x2=pos.x/58;
   	y2=pos.y/58;
   	
	 //if( abs(x2-x1)+abs(y2-y1)==1 )
  	 if( (abs(x1-x2)+abs(y1-y2)) ==1 )
         {
         //	cout<<grid[y1][x1]<<" "<< grid[y2][x2]<<endl;
         	temp=grid[y1][x1];
         	grid[y1][x1]=grid[y2][x2];
         	grid[y2][x2]=temp;
         	//cout<<grid[y1][x1]<<" "<< grid[y2][x2]<<endl;
   		click=0;
   		
   		cout<<score<<endl;
   		
   		
  	 } 
  	 
  
         
         else
         {
         	click=1;
         }
         
         move--;
                
   }
   
   //second swap
   string_score="";
  tscore.setString(string_score); 
  
   
    string_score = to_string(score);
   tscore.setFont(scoreimg);
    tscore.setString(string_score);
    tscore.setPosition(Vector2f(700,10));
    tscore.setCharacterSize( 30 ); 
     tscore.setFillColor( Color::White); 
     
     int tempscore=score;
     
   hmmatch(grid, leo, cam, ele, cre, lamp, deer, gir, score);
   
  if(tempscore<score)
  {
  tscore.setFillColor(Color::Black);
  tscore.setOutlineColor(Color::Black);
//  tscore.setFillColor( Color::Transparent );
   }
   app.draw(tscore);
  
  
  if(move==0 || (gir >=3 && cre >= 3 && deer >= 3 && leo >= 3 && ele >= 3 && cam >= 3) )
  appcheck=4;
     
  
  //cout<<"tm:"<<tempmoves<<"\nm:"<<move<<endl;

 
 
   
  if(tempmoves>move)
  {
  
  movesnum.setFillColor(Color::Black);
  movesnum.setOutlineColor(Color::Black);
   }
  app.draw(movesnum);
   
  
   
  
  
 tempmoves=move;
 

 
 /*
   for(int i=0 ; i<5 ;i++)
    {
  
    	for(int j=0;j<5 ;j++)
    	{
    	cout<<grid[i][j]<<" ";
    	}
    	
    	cout<<endl;
   
   }
 */
 
   
  
   
  
   for(int i=0 ; i<5 ;i++)
    {
  
    	for(int j=0;j<5 ;j++)
    	{
    	
    		if(grid[i][j]==0 && (k>=0  && k<=4))
    		{
    			//t3[0].loadFromFile("sprites/camel.png");
    			//t3[0].loadFromFile("sprites/oink.jpeg");
    			t3[0].loadFromFile("sprites/kowala.png");
    		}
    		
    		else if(grid[i][j]==1 && (k>=0  && k<=4))
    		{
    			//t3[0].loadFromFile("sprites/elephant.png");
    			//t3[0].loadFromFile("sprites/monk.jpeg");
    			t3[0].loadFromFile("sprites/bear.png");
    
    		}
    		
    		else if(grid[i][j]==2 && (k>=0  && k<=4) ) 
    		{
    			//t3[0].loadFromFile("sprites/creature.png");
    			//t3[0].loadFromFile("sprites/racoon.jpeg");
    			t3[0].loadFromFile("sprites/oinky.png");
    			
    		}
    		
    		else if(grid[i][j]==3 && (k>=0  && k<=4) )
    		{
    			t3[0].loadFromFile("sprites/racooon.png");
    			//t3[0].loadFromFile("sprites/sheep.jpeg");
    		}
    		
    		else if(grid[i][j]==4 && (k>=0  && k<=4) )
    		{
    			t3[0].loadFromFile("sprites/coww.png");
    			//t3[0].loadFromFile("sprites/rabbit.jpeg");
    		}
    		
    		else if(grid[i][j]==5 && (k>=0  && k<=4) )
    		{
    			//t3[0].loadFromFile("sprites/lepord.png");
    			t3[0].loadFromFile("sprites/rabbitt.png");
    		}
    		
    		
   
    		Sprite f(t3[0]);
    		f.setPosition(Vector2f (x,y) );
    		
    		//if(x<400)
    		//x+=58;
    		x+=js;
   	 	app.draw(f);
  	  	app.display();
    	}
    	
    	//if(y<=358)
    	{
    		//y+=58;
    		y+=js;
    		x=0;
    	}
    	
    	
    
    }
    
    //in game draws
    
      app.draw( text );
   // app.draw( lblscore );
 
    app.draw(tscore);
    app.draw(moves);
    app.draw(movesnum);
    
    app.draw(leooutbar);
    app.draw(camoutbar);
    app.draw(eleoutbar);
    app.draw(creoutbar);
    app.draw(deeroutbar);
    //app.draw(lampoutbar);
    app.draw(giroutbar);
    
    app.draw(tim);
    
    
     if(leo>=1)
     {
    app.draw(leoinbar1);
     if(leo>=2)
     {
    app.draw(leoinbar2);
    	if(leo>=3)
    app.draw(leoinbar3);
     }  
     }
     
      if(cam>=1)
     {
    app.draw(caminbar1);
     if(cam>=2)
     {
    app.draw(caminbar2);
    	if(cam>=3)
    app.draw(caminbar3);
     }  
     }
     
      if(ele>=1)
     {
    app.draw(eleinbar1);
     if(ele>=2)
     {
    app.draw(eleinbar2);
    	if(ele>=3)
    app.draw(eleinbar3);
     }  
     }
     
      if(cre>=1)
     {
    app.draw(creinbar1);
     if(cre>=2)
     {
    app.draw(creinbar2);
    	if(cre>=3)
    app.draw(creinbar3);
     }  
     }
     
      if(lamp>=1)
     {
    app.draw(lampinbar1);
     if(lamp>=2)
     {
    app.draw(lampinbar2);
    	if(lamp>=3)
    app.draw(lampinbar3);
     }  
     }
     
      if(deer>=1)
     {
    app.draw(deerinbar1);
     if(deer>=2)
     {
    app.draw(deerinbar2);
    	if(deer>=3)
    app.draw(deerinbar3);
     }  
     }
     
     if(gir>=1)
     {
    app.draw(girinbar1);
     if(gir>=2)
     {
    app.draw(girinbar2);
    	if(gir>=3)
    app.draw(girinbar3);
     }  
     }
     
     
   app.draw(frame);  
   app.draw(name1);
   app.draw(name2);
   app.draw(name3);
   app.draw(name4);
   app.draw(name5);
   app.draw(name6);
   
   //app.draw(name6);
 //  app.draw(timer);
   //app.draw(timenum);
  // app.draw(timer);
   
   
    	//	app.draw(backgrund);
    		
    	//	app.draw(backgrund2);
   
    app.display();
//



}



else if(appcheck==3)
{
//app.draw(backus);
app.draw(helpmenu);

app.display();

}


else if(appcheck==4)
{
/*
    (e.type == Event::Closed);
    cout<<"end"<<endl;	
    string_moves = to_string(0);
   movesnum.setFont(scoreimg);
    movesnum.setString(string_moves);
    movesnum.setPosition(Vector2f(700,50));
    movesnum.setCharacterSize( 30 ); 
    movesnum.setFillColor( Color::White);
    app.draw(movesnum);
    
    string_score = to_string(score);
   tscore.setFont(scoreimg);
    tscore.setString(string_score);
    tscore.setPosition(Vector2f(700,10));
    tscore.setCharacterSize( 30 ); 
     tscore.setFillColor( Color::White); 
    app.draw(tscore);
    
    app.display();
   */
  
    if( move>=0 && (gir >=3 && cre >= 3 && deer >= 3 && leo >= 3 && ele >= 3 && cam >= 3) )
    {
    app.draw(win);
    app.display();
    //cout<<"inwon"<<endl;
    }
    else
    {
    app.draw(lost);
    app.display();
   //  cout<<"inlost"<<endl;
    }
   
    
    
}



    y=0; 
    
    	//	app.draw(backgrund);
    		
    	//	app.draw(backgrund2);

    
    
   
    }
    
    return 0;
}





















