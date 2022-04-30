/**
 * @file main.cpp
 * @author Shubhang Gupta (https://github.com/jarvis-1805)
 * @brief Implementation to draw a line using the Bresenham's Circle Drawing algorithm.
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

// Circle Points
void putpixelCirclePoints(int x, int y, int o_x, int o_y, int color) {
  putpixel(x + o_x, y + o_y, color);
  putpixel(y + o_y, x + o_x, color);
  putpixel(y + o_y, -x + o_x, color);
  putpixel(x + o_x, -y + o_y, color);
  putpixel(-x + o_x, -y + o_y, color);
  putpixel(-y + o_y, -x + o_x, color);
  putpixel(-y + o_y, x + o_x, color);
  putpixel(-x + o_x, y + o_y, color);
}

void bcdaLine(int o_x, int o_y, int radius, int color) {
  int x = 0;
  int y = radius;
  int d = 1 - radius;

  putpixelCirclePoints(x, y, o_x, o_y, color);

  while (y > x) {
    if (d < 0) {             // Select E
      d += 2 * x + 3;
    } else {                 // Select SE
      d += 2 * (x - y) + 5;
      y--;
    }
    x++;
    putpixelCirclePoints(x, y, o_x, o_y, color);
  }
}

int main(void) {
  int o_x, o_y;     // origin (x, y)
  int radius;
  cout << "Enter the center of the circle (x, y): ";
  cin >> o_x >> o_y;
  cout << "Enter the radius of the circle: ";
  cin >> radius;

  int gd = DETECT, gm, color;
  initgraph(&gd, &gm, NULL);
  bcdaLine(o_x, o_y, radius, WHITE);

  delay(10e8);
  closegraph();

  return 0;
}
