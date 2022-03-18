#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<iostream>
#include<stdio.h>
#include<windows.h>
using namespace std;
void body();
void end();
void hit();//function prototype
//void hit3();
//void ang15();
void left15();
void right15();

void left30();
void right30();

void left60();
void right60();

void up90();

void left45();
void right45();
int score=0;

/*global variables*/
int a=200,b=700,c=400,d=700,ch,n=1,ns=0,nu=0;
int scr=1;
int val=500;
float e=500,f=100;
int ab;
int ref,dif;

void clearline()
{
	setcolor(BLACK);
	line(a,b,c,d);
}
void clearcircle()
{
	setcolor(BLACK);
	circle(e,f,20);
//	delay(20);
}

int main()
{ 
	initwindow(1200,800);
	
body();

getch();
	
}

void body()
{
a=200,b=700,c=400,d=700,ch,n=1,ns=0,nu=0;
val=500;
e=500,f=100;
score=0;
int inp;
POINT cursorPosition;
str:
	
cleardevice();
settextstyle(10,HORIZ_DIR,6);	
outtextxy(300,300,"PRESS 1 TO START");

char msg[128];
sprintf(msg, "SCORE=%d", score);

inp=getch();
if(inp==49)
{

cleardevice();
line(a,b,c,d);

setcolor(BLUE);
settextstyle(10,HORIZ_DIR,8);
outtextxy(250,10,"BOUNCING BALL");
settextstyle(10,HORIZ_DIR,1);
setcolor(YELLOW);
outtextxy(1020,600," Created");
outtextxy(1020,620,"   and");
outtextxy(1020,640," Developed");
outtextxy(1020,660,"    BY");
settextstyle(6,HORIZ_DIR,1);
setcolor(RED);
outtextxy(1020,680,"  RAJESH");

line(a,b,c,d);
	ref=200;

while(1)
{ 
sprintf(msg, "SCORE=%d", score);
settextstyle(8,HORIZ_DIR,3);
outtextxy(10, 30, msg);

setcolor(WHITE);
 
 line(80,80,80,800);
line(1020,80,1020,800);
line(80,80,1020,80);
 
 line(a,b,c,d);
 
 if(a>=80&&a<=820)
 clearline();
 
       GetCursorPos(&cursorPosition);
	    ab=cursorPosition.x;
	    
	    if(ab<ref)
	    { dif=ref-ab;
		  c=c-dif;
		}
		if(ab>ref)
		{  dif=ab-ref;
		c=c+dif;
		}
		
	    ref=cursorPosition.x;	    	   
		a=cursorPosition.x; 
			     	    	    
	    setcolor(WHITE);
	    if(a>=80&&a<=820)
	    {
		 line(a,b,c,d);
	}
/*	if(kbhit())
	{
	clearline();
		ch=getch();
		if(ch==75&&a>100)  //left
		{  
			a=a-20;			
			c=c-20;								
		}
		if(ch==77&&c<1000) //right
		{ 
			a=a+20;							
			c=c+20;		
		}		
	}*/
	
clearcircle();
hit();


setcolor(YELLOW);
	circle(e,f,20);
	delay(1.0);
}  
}
else
goto str;	
}

void hit()
{ 
	/*program for changing balll direction*/	
	if(n==1&&f<800)
	{ f=f+5;  }  
	
if(a+200>=e&&c-200<=e&&f==680)
	{ 
		n=3;
		val=a-e;
	}

/*left hit paths*/

if(val<=0&&val>=-20)
{ left15();}
if(val<=-21&&val>=-40)
{ left30();}
if(val<=-41&&val>=-60)
{ left45(); }
if(val<=-61&&val>=-80)
{ left60(); }

/*middle hit path*/

if(val<=-81&&val>=-120)
{ up90();}

/*right hit paths*/

if(val<=-121&&val>=-140)
{ right60(); }
if(val<=-141&&val>=-160)
{ right45(); }
if(val<=-161&&val>=-180)
{right30(); }
if(val<=-181&&val>=-200)
{ right15();}


if(f>681)
{  end();
   }
   
}

void up90()
{  
	if(n==3)
	{ f=f-10;
	 if(f<=100)
	 { n=21;
	  ns=3;
	}
	}
	if(ns==3)
	{ f=f+10;
	}
		if(f>=680&&a+200>=e&&c-200<=e)
   { 
     
	   ns=30;	
   }
   
}

void end()
{ int chk=0;
	cleardevice();
	settextstyle(10,HORIZ_DIR,6);
	setcolor(WHITE);
	outtextxy(380,300,"GAME OVER");
	outtextxy(300,400,"PRESS 3 TO EXIT");
	outtextxy(300,500,"PRESS 1 TO RESTART");
	chk=getch();
	if(chk==51)
	{ exit(1);
	}
	if(chk==49)
	{ body();
	}
}

void right60()
{ 
	if(n==3)
	{ e=e+2.8;
	f=f-5;
	 if(e>=1000) //right hit
	 { ns=3;
	   n=21;
	  }
	 if(f<=100) //top hit
	 { ns=13;
	 n=21;
	 }
	}
	if(ns==13)
	{
		e=e+2.8;
		f=f+5;
		if(e>=1000) //right hit
		ns=14;
	}
	if(ns==14)
	{ e=e-2.8;
	f=f+5;
	}
	
	if(ns==3)
	{
		e=e-2.8;
		f=f-5;
		if(f<=100) //top hit
		ns=4;
	}
	if(ns==4)
	{ e=e-2.8;
	f=f+5;
	
	}
		if(f>=680&&a+200>=e&&c-200<=e)
   { 
     if(f>=680&&f<=683)
      {
        score++;
       }
	   ns=30;	
   }
	
}

void left60()
{ 
	if(n==3)
	{ e=e-2.8;
	f=f-5;
	 if(e<=100) //left hit
	 { n=21;
	 ns=3;
	 }
	 if(f<=100) //top hit
	 { ns=13;
	 n=21;
	 }
	}
    if(ns==13)
    {
    	e=e-2.8;
    	f=f+5;
    	if(e<=100) //left hit
    	ns=14;
	}
	if(ns==14)
	{
		e=e+2.8;
		f=f+5;
	}
		
	if(ns==3)
	{
		e=e+2.8;
		f=f-5;
		if(f<=100) //top hit
		ns=4;
	}
	if(ns==4)
	{
		e=e+2.8;
		f=f+5;
		if(e>=1000) //right hit
		ns=5;
	}
	if(ns==5)
	{
		e=e-2.8;
		f=f+5;
	}
	if(f>=680&&a+200>=e&&c-200<=e)
   { 
     if(f>=680&&f<=681)
      {
        score++;
       }
	   ns=30;	
   }
	
}

void left30()
{  
	if(n==3)
	{ e=e-9.1;
	f=f-5;
	if(e<=100) //left hit
	{ n=21;
 	ns=3;
}
	}
	if(ns==3)
	{
		e=e+9.1;
		f=f-5;
		if(f<=100) //top hit
		ns=4;
		if(e>=1000)
		ns=14; //right hit
	}
	if(ns==14)
	{
		e=e-9.1;
		f=f-5;
		if(f<=100) //top hit
		ns=15;
	}
	if(ns==15)
	{
	e=e-9.1;
	f=f+5;
	if(e<=100) //left hit
	ns=16;	
	}
	if(ns==16)
	{
		e=e+9.1;
		f=f+5;
	}
	if(ns==4)
	{
		e=e+9.1;
		f=f+5;
		if(e>=1000) //right hit
		ns=5;		
	}
	if(ns==5)
	{
		e=e-9.1;
		f=f+5;
		if(e<=100) //left hit
		 ns=6;
	}
	if(ns==6)
	{
		e=e+9.1;
		f=f+5;
	}
	
	if(f>=680&&a+200>=e&&c-200<=e)
{ 
if(f>=680&&f<=681)
{
score++;
}
	ns=30;	
}
	
}
float re=6,rf=3.3;
void right30()
{  
	if(n==3)
	{
		e=e+re;
		f=f-rf;
		if(e>=1000) //right hit
		{ n=21;
		ns=3;
		}
	}
	if(ns==3)
	{
		e=e-re;
		f=f-rf;
		if(f<=100) //top hit
		ns=4;
		if(e<=100) //left hit
		ns=14;
	}
	if(ns==14)
	{
		e=e+re;
		f=f-rf;
		if(f<=100) //top hit
		ns=15;
	}
	if(ns==15)
	{ e=e+re;
	f=f+rf;
	if(e>=1000) //right hit
	ns=16;
	}
	if(ns==16)
	{ e=e-re;
	f=f+rf;		
	}
	
	
	if(ns==4)
	{
		e=e-re;
		f=f+rf;
		if(e<=100) //left hit
		ns=5;
	}
	if(ns==5)
	{
		e=e+re;
		f=f+rf;
		if(e>=1000) //right hit
		ns=6;
	}
	if(ns==6)
	{
		e=e-re;
		f=f+rf;
	}
	
	if(f>=680&&a+200>=e&&c-200<=e)
{ 
if(f>=680&&f<=682)
{
score++;
}
	ns=30;	
}
	
}



void left15()
{ 
//first path
   if(n==3)
   {   
     e=e-8.25;
     f=f-2.5;
     if(e<=100) //hit left
    { ns=2;
      n=20;
	 }	
    }	
	
if(ns==2)
{ e=e+8.25;
f=f-2.25;
if(e>=1000) //hit right
{ ns=3;
	
}
}

if(ns==3)
{
	e=e-8.25;
	f=f-2.5;
	if(f<=100) //hit top
{ns=4;
}
if(e<=100) //hit left
{ ns=14;

}
}
if(ns==14)
{
	e=e+8.25;
	f=f-2.5;
	if(f<=100) //hit top
	{ ns=15;
	}
}
if(ns==15)
{
	e=e+8.25;
	f=f+2.5;
	if(e>=1000) //hit right
	ns=16;
}
if(ns==16)
{
	e=e-8.25;
	f=f+2.5;
	if(e<=100) //hit left
	ns=17;
}
if(ns==17)
{ e=e+8.25;
f=f+2.5;
}
if(ns==4)
{
	e=e-8.25;
	f=f+2.5;
	if(e<=100) //hit left
{ ns=5;	
}
}

if(ns==5)
{ e=e+8.25;
	f=f+2.5;
if(e>=1000)
ns=6;	
}
if(ns==6)
{ e=e-8.25;
f=f+2.5;
if(e<=100)
{ ns=7;
}
}
if(ns==7)
{
	e=e+8.25;
	f=f+2.5;
}

      if(f>=680&&a+200>=e&&c-200<=e)
     { 
     if(f>=680&&f<=681)
     {
      score++;
    }
	ns=30;	
   }

}

void right15()
{ 
	if(n==3)
	{
		e=e+8.25;
		f=f-2.5;
		if(e>=1000) //hit right
		{
		ns=2;
		n=20;}
	}
	if(ns==2) 
	{
	e=e-8.25;
	f=f-2.5;
	if(e<=100) //hit left
	 ns=3;	
	 if(f<=100) //hit top
	 ns=13;
	}
	if(ns==13)
	{
		e=e-8.25;
		f=f+2.5;
		if(e<=100) //hit left
		ns=14;
	}
	if(ns==14)
	{e=e+8.25;
	f=f+2.5;
	if(e>=1000) //hit right
	ns=15;
	
	}
	if(ns==15)
	{		
	e=e-8.25;
	f=f+2.5;
		
	}
	
	if(ns==3)
	{ e=e+8.25;
	f=f-2.5;
	if(f<=100) //top hit
	{ ns=4;
	e=e+8.25;
	f=f+2.5;}
	if(e>=1000) //left-right
	ns=16;
	}
	if(ns==16)
	{ e=e-8.25;
	f=f-2.5;
	if(f<=100)// right-top
	{ns=17;
	}
	}
	if(ns==17)
	{
		e=e-8.25;
		f=f+2.5;
		if(e<=100) //left hit
		{ns=18;
		}
	}
	if(ns==18)
	{ e=e+8.25;
	f=f+2.5;
	if(e>=1000) //right hit
	  ns=19;
	}
	if(ns==19)
	{ e=e-8.25;
	f=f+2.5;
	}
	
	if(ns==4)
	{		
	e=e+8.25;
	f=f+2.5;
		if(e>=1000)
		ns=5;
	}
	if(ns==5)
	{
		e=e-8.25;
		f=f+2.5;
		if(e<=100)
		ns=6;
	}
	if(ns==6)
	{
		e=e+8.25;
		f=f+2.5;
		if(e>=1000) //hit right
		ns=7;
	}
	if(ns==7)
	{
		e=e-8.25;
		f=f+2.5;
	}
	if(f>=680&&a+200>=e&&c-200<=e)
     { if(f>=680&&f<=681)
       {
        score++;
        }
	   ns=30;	
      }
	
}


void left45()
{  
	if(n==3)
	{
		e=e-5; // e++;
		f=f-5; // f--;
		if(e<=100) //left hit
		{ 
			n=21;
			ns=1;
		}		
		if(f<=100) //top hit	
		{
		ns=11;	
          n=21;
        }
	}
	
	if(ns==11)
	{ e=e-5;
	f=f+5;
	if(e<=100) //left hit
	ns=12;
	}
	if(ns==12)
	{ 
	  e=e+5;
	  f=f+5;
	}
	
	if(ns==1)
		{
			e=e+5;
			f=f-5;
			if(f<=100) //top hit
			 ns=20;
			
	 	}
	if(ns==20)
	{
		e=e+5;
		f=f+5;
		if(e>=1000) //right hit
	    ns=21;
	}	
	if(ns==21)
	{
		e=e-5;
		f=f+5;
	
	}
	if(f>=680&&a+200>=e&&c-200<=e)
     { if(f>=680&&f<=681)
       {
         score++;
        }
	      ns=30;	
      }
}
 void right45()
 { 

	if(n==3)
	{
		e=e+5;
		f=f-5;
		if(e>=1000) //right hit
		{ n=21;
			ns=3;
		}
		if(f<=100) // top hit
		{   ns=13;
		   n=21;
		}
	}
	
	if(ns==13)
	{
		e=e+5;
		f=f+5;
		if(e>=1000) //right hit
	    ns=14;
	}
	if(ns==14)
	{
		e=e-5;
		f=f+5;
	}
	
	if(ns==3) 
	{ e=e-5;
	f=f-5;
		if(f<=100) //top hit
		ns=4;
	}
	if(ns==4)
	{
		e=e-5;
		f=f+5;
		if(e<=100) //left hit
		ns=5;
	}
	if(ns==5)
	{
		e=e+5;
		f=f+5;
	}
		if(f>=680&&a+200>=e&&c-200<=e)
      {   if(f>=680&&f<=681)
         {
           score++;
         }
	       ns=30;	
      }
}
