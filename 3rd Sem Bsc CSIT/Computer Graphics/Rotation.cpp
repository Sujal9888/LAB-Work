#include <iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
# define PI 3.14159
using namespace std;

int main(){
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "");
	
	float angle;
	int ax, ay, bx, by, cx, cy;
	int xp, yp;
	int ax1,ay1,bx1, by1, cx1,cy1;
	
	angle=angle*(PI/180);
	cout<<"Enter Pivot point(xp, yp):";
	cin>>xp>>yp;
	cout<<"Enter A(x,y): ";
	cin>>ax>>ay;
	cout<<"Enter B(x,y):";
	cin>>bx>>by;
	cout<<"Enter C(x,y):";
	cin>>cx>>cy;
	cout<<"Enter angle:";
	cin>>angle;
		
	//For A
	ax1=xp+(ax-xp)*cos(angle)-(ay-yp)*sin(angle);
	ay1=yp+(ax-xp)*sin(angle)+(ay-yp)*sin(angle);
	
	// For B
	bx1=xp+(bx-xp)*cos(angle)-(by-yp)*sin(angle);
	by1=yp+(bx-xp)*sin(angle)+(by-yp)*sin(angle);
	
	// For c
	cx1=xp+(cx-xp)*cos(angle)-(cy-yp)*sin(angle);
	cy1=yp+(cx-xp)*sin(angle)+(cy-yp)*sin(angle);
	
	cout << "\nRotated Triangle Coordinates:" << endl;
    cout << "A'(" << ax1 << "," << ay1 << ")" << endl;
    cout << "B'(" << bx1 << "," << by1 << ")" << endl;
    cout << "C'(" << cx1 << "," << cy1 << ")" << endl;
	
	// Original 
	setcolor(WHITE);
	line(ax, ay,bx,by);
	line(bx,by,cx,cy);
	line(cx,cy,ax, ay);
	
	//Roteated
	setcolor(RED);a
	line(ax1,ay1,bx1,by1);
	line(bx1,by1,cx1,cy1);
	line(cx1,cy1,ax1,ay1);
	
	getch();
	closegraph();
	return 0;
}
