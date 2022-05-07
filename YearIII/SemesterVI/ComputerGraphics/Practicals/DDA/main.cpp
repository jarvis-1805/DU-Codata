/**
 * @file main.cpp
 * @author Shubhang Gupta (https://github.com/jarvis-1805)
 * @brief Implementation to draw a line using the Digital Differential Analyzer (DDA) algorithm.
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

void ddaLine(int x0, int y0, int x1, int y1, int color) {
  // If the start and end points are same
  if (x0 == x1 && y0 == y1) {
    putpixel(x0, y0, color);
  } else {
    double x, y;

    double dy = y1 - y0;         // difference in y co-ordinates
    double dx = x1 - x0;         // difference in x co-ordinates

    double m = dy / dx;          // slope of the line

    bool isLtoR = (x0 < x1);    // isLtoR → is line from Left to Right

    if (std::abs(m) <= 1) {
      if (isLtoR) {
        for (x = x0, y = y0; x <= x1; x++) {
          putpixel(x, y, color);
          y += m;
        }
      } else {
        for (x = x1, y = y1; x >= x0; x--) {
          putpixel(x, y, color);
          y -= m;
        }
      }
    } else if (std::abs(m) > 1) {
      if (isLtoR) {
        for (y = y0, x = x0; y <= y1; y++) {
          putpixel(x, y, color);
          x += (1 / m);
        }
      } else {
        for (y = y1, x = x1; y >= y0; y--) {
          putpixel(x, y, color);
          x -= (1 / m);
        }
      }
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
  ddaLine(x0, y0, x1, y1, WHITE);

  delay(10e8);
  closegraph();

  return 0;
}
