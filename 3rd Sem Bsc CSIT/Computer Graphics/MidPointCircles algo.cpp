#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;

void drawCirclePoints(int xc, int yc, int x, int y){
	
	putpixel(xc +x, yc+y, WHITE);
	putpixel(xc -x, yc+y, WHITE);
	putpixel(xc +x, yc-y, WHITE);
	putpixel(xc -x, yc-y, WHITE);
	putpixel(xc +y, yc+x, WHITE);	
	putpixel(xc -y, yc+x, WHITE);
	putpixel(xc +y, yc-x, WHITE);
	putpixel(xc -y, yc-x, WHITE);			
}
int main(){
	int xc, yc, r;
	cout<<"Enter center (xc,yc):";
	cin>> xc >> yc;
	cout<<"Enter radius:";
	cin>> r;
	
	int gd= DETECT, gm;
	initgraph(&gd,&gm,"");
	
	int x=0;
	int y=r;
	int p=1-r;
	
	cout<<"\nMid-Point Circle Algorithm Table\n";
	cout<<"K\tPk\t(xk+1,yk+1)\t2xk+1\t2yk+1\n";
	cout<<"----------------------------------------------------------\n";
	int k=0;
	drawCirclePoints(xc, yc, x, y);
  while (x < y) {
        int pk = p;
        int x_next;
        int y_next;
		
		if(pk<0){
			x_next=x+1;
			y_next=y;
			p=p+2*x_next+1;
		}
		else{
			x_next=x+1;
			y_next=y-1;
			p=p+2*(x_next-y_next)+1;
		}
        cout << k << "\t"
			<< pk<< "\t(" 
			<< x_next << "," << y_next << ")\t\t"
			<<2*x_next<< "\t" 
			<<2*y_next<< endl;

        x = x_next;
        y = y_next;
        drawCirclePoints(xc, yc, x, y);
   		k++;
    }

    getch();
    closegraph();
    return 0;
}
