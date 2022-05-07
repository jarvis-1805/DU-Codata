/**
 * @file main.cpp
 * @author Shubhang Gupta (https://github.com/jarvis-1805)
 * @brief Implementation to draw a line using the Bresenham's Line Drawing algorithm.
 * @version 0.1
 * @date 2022-01-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include <cmath>

using namespace std;

void bldaLine(int x0, int y0, int x1, int y1, int color) {
  // If the start and end points are same
  if (x0 == x1 && y0 == y1) {
    putpixel(x0, y0, color);
  } else {
    int dx = x1 - x0;
    int dy = y1 - y0;

    float m = float(dy) / float(dx);
    if (0 < m && m < 1) {
      int d = 2 * dy - dx;            // Initial value of d
      int incr_E = 2 * dy;            // Increment used for move to E
      int incr_NE = 2 * (dy - dx);    // Increment used for move to NE

      int x = x0;
      int y = y0;

      putpixel(x, y, color);          // The start pixel

      while (x < x1) {
        if (d <= 0) {                 // Choose E
          d += incr_E;
          x++;
        } else {
          d += incr_NE;
          x++;
          y++;
        }
        putpixel(x, y, color);
      }
    } else {
      cout << "\nThe slope must be between 0 and 1!\nCurrent slope: " << m;
      exit(1);
    }
  }
}

int main(void) {
  int x0, y0, x1, y1;
  cout << "Enter the left endpoint (x0, y0): ";
  cin >> x0 >> y0;
  cout << "Enter the right endpoint (x1, y1): ";
  cin >> x1 >> y1;

  int gd = DETECT, gm, color;
  initgraph(&gd, &gm, NULL);
  bldaLine(x0, y0, x1, y1, WHITE);

  delay(10e8);
  closegraph();

  return 0;
}
