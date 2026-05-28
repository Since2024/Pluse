#include <iostream>
#include <graphics.h> // Requires a graphics library configured in your IDE

using namespace std;

// Function to plot the 8-way symmetrical points of the circle
void plotCirclePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

// Mid-point circle drawing algorithm implementation
void drawCircleMidpoint(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int p = 1 - r; // Initial decision parameter

    // Plot the initial point
    plotCirclePoints(xc, yc, x, y);

    // Calculate next points until x reaches y (45 degrees)
    while (x < y) {
        x++;

        if (p < 0) {
            // Midpoint is inside the perimeter; choose E
            p = p + 2 * x + 1;
        } else {
            // Midpoint is outside or on the perimeter; choose SE
            y--;
            p = p + 2 * x - 2 * y + 1;
        }
        
        plotCirclePoints(xc, yc, x, y);
    }
}

int main() {
    // Initialize graphics window
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int xc, yc, r;

    cout << "Enter the center coordinates (xc yc): ";
    cin >> xc >> yc;
    cout << "Enter the radius of the circle: ";
    cin >> r;

    cout << "Drawing circle..." << endl;
    drawCircleMidpoint(xc, yc, r);

    // Hold the output screen
    getch();
    closegraph();
    return 0;
}