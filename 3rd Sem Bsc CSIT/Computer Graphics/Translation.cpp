#include <iostream>
#include <graphics.h>
#include <conio.h>
using namespace std;

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");

    int ax, ay, bx, by, cx, cy;

    // Input original triangle points
    cout << "Enter A(X,Y): ";
    cin >> ax >> ay;
    cout << "Enter B(X,Y): ";
    cin >> bx >> by;
    cout << "Enter C(X,Y): ";
    cin >> cx >> cy;

    int tri[3][3] = {
        {ax, bx, cx},   
        {ay, by, cy},   
        {1,  1,  1}     
    };

    // Translation vector
    int tx, ty;
    cout << "Enter translation vector (tx,ty): ";
    cin >> tx >> ty;

    int T[3][3] = {
        {1, 0, tx},
        {0, 1, ty},
        {0, 0, 1}
    };

    int tri1[3][3] = {0};

    for(int i = 0; i < 3; i++) {       
        for(int j = 0; j < 3; j++) {   
            tri1[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                tri1[i][j] += T[i][k] * tri[k][j];
            }
        }
    }
    cout<<"\nTranslated Triangle Coordinates:\n";
    cout << "A'(" << tri1[0][0] << "," << tri1[1][0] << ")" << endl;
    cout << "B'(" << tri1[0][1] << "," << tri1[1][1] << ")" << endl;
    cout << "C'(" << tri1[0][2] << "," << tri1[1][2] << ")" << endl;


    // Draw original triangle in WHITE
    setcolor(WHITE);
    line(tri[0][0], tri[1][0], tri[0][1], tri[1][1]);
    line(tri[0][1], tri[1][1], tri[0][2], tri[1][2]);
    line(tri[0][2], tri[1][2], tri[0][0], tri[1][0]);

    // Draw translated triangle in RED
    setcolor(RED);
    line(tri1[0][0], tri1[1][0], tri1[0][1], tri1[1][1]);
    line(tri1[0][1], tri1[1][1], tri1[0][2], tri1[1][2]);
    line(tri1[0][2], tri1[1][2], tri1[0][0], tri1[1][0]);

    getch();
    closegraph();
    return 0;
}

