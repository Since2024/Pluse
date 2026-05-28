#include <iostream>
#include <graphics.h> // Requires a graphics library like WinBGIM or Turbo C++

using namespace std;

// Function to plot pixels in all 8 octants
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

// Bresenham's Circle Drawing Algorithm
void drawCircleBresenham(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r; // Initial decision parameter

    // Plot the starting points
    plotCirclePoints(xc, yc, x, y);

    // Loop until the x-coordinate meets or crosses the y-coordinate
    while (x <= y) {
        x++;

        // Update decision parameter and y-coordinate
        if (d < 0) {
            // Choose the pixel to the right (E)
            d = d + 4 * x + 6;
        } else {
            // Choose the pixel diagonally down (SE)
            y--;
            d = d + 4 * (x - y) + 10;
        }

        plotCirclePoints(xc, yc, x, y);
    }
}

int main() {
    // Initialize graphics window
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int xc, yc, r;

    cout << "Enter center coordinates (xc yc): ";
    cin >> xc >> yc;
    cout << "Enter radius: ";
    cin >> r;

    cout << "Drawing circle using Bresenham's Algorithm..." << endl;
    drawCircleBresenham(xc, yc, r);

    // Keep the window open until a key is pressed
    getch();
    closegraph();
    return 0;
}