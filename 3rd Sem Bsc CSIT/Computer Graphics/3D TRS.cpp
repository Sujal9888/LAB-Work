#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

struct Point3D {
    float x, y, z;
};

// ---------- TRANSFORMATIONS ----------
void translate(Point3D &p, float tx, float ty, float tz) {
    p.x += tx; p.y += ty; p.z += tz;
}

void scale(Point3D &p, float sx, float sy, float sz) {
    p.x *= sx; p.y *= sy; p.z *= sz;
}

void rotateX(Point3D &p, float angle) {
    float r = angle * 3.1416 / 180;
    float y = p.y * cos(r) - p.z * sin(r);
    float z = p.y * sin(r) + p.z * cos(r);
    p.y = y; p.z = z;
}

void rotateY(Point3D &p, float angle) {
    float r = angle * 3.1416 / 180;
    float x = p.x * cos(r) + p.z * sin(r);
    float z = -p.x * sin(r) + p.z * cos(r);
    p.x = x; p.z = z;
}

void rotateZ(Point3D &p, float angle) {
    float r = angle * 3.1416 / 180;
    float x = p.x * cos(r) - p.y * sin(r);
    float y = p.x * sin(r) + p.y * cos(r);
    p.x = x; p.y = y;
}

// ---------- DRAW FUNCTION ----------
void drawCube(Point3D p[], int color) {
    setcolor(color);

    int edges[12][2] = {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };

    for(int i=0; i<12; i++) {
        int x1 = p[edges[i][0]].x + p[edges[i][0]].z/2 + 300;
        int y1 = p[edges[i][0]].y + p[edges[i][0]].z/2 + 200;

        int x2 = p[edges[i][1]].x + p[edges[i][1]].z/2 + 300;
        int y2 = p[edges[i][1]].y + p[edges[i][1]].z/2 + 200;

        line(x1, y1, x2, y2);
    }
}

// ---------- MAIN ----------
int main() {

    // Initialize once
    initwindow(800, 600);

    int choice;
    do {
        // Cube reset
        Point3D cube[8] = {
            {50,50,50}, {100,50,50}, {100,100,50}, {50,100,50},
            {50,50,100}, {100,50,100}, {100,100,100}, {50,100,100}
        };

        Point3D cube2[8];
        for(int i=0;i<8;i++) cube2[i] = cube[i];

        cleardevice();  // clear previous drawings

        cout << "\n--- 3D Transformations Menu ---\n";
        cout << "1. Translation\n2. Scaling\n3. Rotation\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        drawCube(cube, WHITE);
        setcolor(WHITE);
        outtextxy(10,10,(char*)"WHITE: Original Cube");

        if(choice == 1) {
            float tx, ty, tz;
            cout << "Enter tx ty tz: ";
            cin >> tx >> ty >> tz;

            for(int i=0;i<8;i++)
                translate(cube2[i], tx, ty, tz);

            drawCube(cube2, RED);
            setcolor(RED);
            outtextxy(10,30,(char*)"RED: Translated Cube");
        }

        else if(choice == 2) {
            float sx, sy, sz;
            cout << "Enter sx sy sz: ";
            cin >> sx >> sy >> sz;

            for(int i=0;i<8;i++)
                scale(cube2[i], sx, sy, sz);

            drawCube(cube2, CYAN);  // visible color
            setcolor(CYAN);
            outtextxy(10,30,(char*)"CYAN: Scaled Cube");
        }

        else if(choice == 3) {
            int axis;
            float angle;

            cout << "Rotate about:\n1. X-axis\n2. Y-axis\n3. Z-axis\n";
            cout<<"Enter Axis choice:";
            cin >> axis;

            cout << "Enter angle: ";
            cin >> angle;

            for(int i=0;i<8;i++) {
                if(axis == 1) rotateX(cube2[i], angle);
                else if(axis == 2) rotateY(cube2[i], angle);
                else if(axis == 3) rotateZ(cube2[i], angle);
            }

            drawCube(cube2, YELLOW);
            setcolor(YELLOW);
            outtextxy(10,30,(char*)"YELLOW: Rotated Cube");
        }

        if(choice != 4){
            cout << "\nPress any key in graphics window...";
            getch();
        }

    } while(choice != 4);

    closegraph();
    return 0;
}
