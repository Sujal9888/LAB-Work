#include <graphics.h>
#include <conio.h>

/* Clipping window */
float xmin = 100, ymin = 100, xmax = 300, ymax = 250;

/* Liang–Barsky Algorithm */
void liangBarsky(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    float p[4] = { -dx, dx, -dy, dy };
    float q[4] = { x1 - xmin, xmax - x1, y1 - ymin, ymax - y1 };

    float u1 = 0.0, u2 = 1.0;

    for (int i = 0; i < 4; i++)
    {
        if (p[i] == 0)
        {
            if (q[i] < 0)
                return;   // Line parallel and outside
        }
        else
        {
            float u = q[i] / p[i];

            if (p[i] < 0)   // Entering point
            {
                if (u > u2) return;  // Reject immediately
                if (u > u1) u1 = u;
            }
            else            // Leaving point
            {
                if (u < u1) return;  // Reject immediately
                if (u < u2) u2 = u;
            }
        }
    }

    /* Clipped points (use float for accuracy) */
    float cx1 = x1 + u1 * dx;
    float cy1 = y1 + u1 * dy;
    float cx2 = x1 + u2 * dx;
    float cy2 = y1 + u2 * dy;

    setcolor(RED);
    line(cx1, cy1, cx2, cy2);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    /* Draw clipping window */
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    /* Original line */
    float x1 = 50, y1 = 200, x2 = 350, y2 = 150;
    setcolor(YELLOW);
    line(x1, y1, x2, y2);

    delay(2000);

    /* Clear and redraw clipped line */
    cleardevice();
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);
    liangBarsky(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

