/**
 * @file main.cpp
 * @author Shubhang Gupta (https://github.com/jarvis-1805)
 * @brief Write a program to clip a line using Cohen and Sutherland line clipping algorithm.
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <vector>

using namespace std;

typedef unsigned int outcode;
enum _boolean {_false, _true};
enum {
  _top = 0x1,
  _bottom = 0x2,
  _right = 0x4,
  _left = 0x8
};

// Coumputing the outode
outcode compoutcode(double _x, double _y, double _xmin, double _xmax, double _ymin, double _ymax) {
  outcode code = 0;
  if (_y > _ymax)
    code |= _top;
  else if (_y < _ymin)
    code |= _bottom;
  else if (_x > _xmax)
    code |= _right;
  else if (_x < _xmin)
    code |= _left;
  
  return code;
}

/* Cohen-Sutherland clipping algorithm for line P0 = x0, y0 to P1 = (x1, y1) and
 * clip rectangle with diagonal from (xmin, ymin) to (xmax, ymax)
 */
void cohen_sutherland_line_clip(double _x0, double _y0, double _x1, double _y1, double _xmin, double _xmax, double _ymin, double _ymax) {
  // Outcodes for P0, P1, and whatever point lies outside the clip rectangle
  outcode outcode0, outcode1, outcodeOut;
  _boolean accept = _false, done = _false;
  outcode0 = compoutcode(_x0, _y0, _xmin, _xmax, _ymin, _ymax);
  outcode1 = compoutcode(_x1, _y1, _xmin, _xmax, _ymin, _ymax);

  do {
    if (!(outcode0 | outcode1)) {
      accept = _true;
      done = _true;
    } else if (outcode0 & outcode1) {
      done = _true;
    } else {
      /* Failed both tests, so calculate the line segment to clip
       * from an outside to an intersection with clip edge.
       */
      double x, y;

      // At least one endpoint is outside the clip rectangle; pick it.
      outcodeOut = outcode0 ? outcode0 : outcode1;

      /* Now finding the intersection point;
       * using formulas y = y0 + slope * (x - x0),
       *                x = x0 + (1/slope) * (y - y0)
       */
      if (outcodeOut & _top) {                 // Divide line at top of clip rectangle
        x = _x0 + (_x1 - _x0) * (_ymax - _y0) / (_y1 - _y0);
        y = _ymax;
      } else if (outcodeOut & _bottom) {       // Divide line at bottom of clip rectangle
        x = _x0 + (_x1 - _x0) * (_ymin - _y0) / (_y1 - _y0);
        y = _ymin;
      } else if (outcodeOut & _right) {        // Divide line at right of clip rectangle
        y = _y0 + (_y1 - _y0) * (_xmax - _x0) / (_x1 - _x0);
        x = _xmax;
      } else {                                 // Divide line at top of clip rectangle
        y = _y0 + (_y1 - _y0) * (_xmin - _x0) / (_x1 - _x0);
        x = _xmin;
      }

      /* Now we move outside point to intersection point to clip,
       * and get ready for the next pass.
       */
      if (outcodeOut == outcode0) {
        _x0 = x;
        _y0 = y;
        outcode0 = compoutcode(_x0, _y0, _xmin, _xmax, _ymin, _ymax);
      } else {
        _x1 = x;
        _y1 = y;
        outcode1 = compoutcode(_x1, _y1, _xmin, _xmax, _ymin, _ymax);
      }
    }     // Subdivide
  } while (done == _false);
  
  if (accept) {
    line(_x0, _y0, _x1, _y1);
    cout << "\nThe clipped co-ordinates of line are:"
        << "\n(x0, y0) : (" << _x0 << ", " << _y0 << ")"
        << "\n(x1, y1) : (" << _x1 << ", " << _y1 << ")"
        << endl;
  }
}

int main() {
	cout << "\n============ COHEN AND SUTHERLAND ALGORITHM ============\n";
  int x0, y0, x1, y1;
  int xmin, xmax, ymin, ymax;
  int lines_count;
  vector<vector<int> > lines;
  vector<int> point;

  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  setbkcolor(RED);

  cout << "\n\nEnter the co-ordinates of the rectangle:";
  cout << "\nXmin : ";
  cin >> xmin;
  cout << "Xmax : ";
  cin >> xmax;
  cout << "Ymin : ";
  cin >> ymin;
  cout << "Ymax : ";
  cin >> ymax;

  rectangle(xmin, ymin, xmax, ymax);

  cout << "\nEnter the no. of lines: ";
  cin >> lines_count;

  for (int i = 0; i < lines_count; i++) {
    cout << "\nEnter the co-ordinates of the line " << i+1 << " :";
    cout << "\nx0 : ";
    cin >> x0;
    cout << "y0 : ";
    cin >> y0;
    cout << "x1 : ";
    cin >> x1;
    cout << "y1 : ";
    cin >> y1;

    point.push_back(x0);
    point.push_back(y0);
    point.push_back(x1);
    point.push_back(y1);

    lines.push_back(point);

    point.clear();
  }

  // The entered co-ordinates of lines
  // for (int i = 0; i < lines_count; i++) {
  //   for (int j = 0; j < 4; j++) {
  //     cout << lines[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cout << "\nThe line before clipping...\n";
  for (int i = 0; i < lines_count; i++) {
    x0 = lines[i][0];
    y0 = lines[i][1];
    x1 = lines[i][2];
    y1 = lines[i][3];
    line(x0, y0, x1, y1);
  }

  delay(3000);
  cleardevice();
  delay(200);

  cout << "\nThe line after clipping...\n";
  rectangle(xmin, ymin, xmax, ymax);
  setlinestyle(DOTTED_LINE, 1, 1);

  for (int i = 0; i < lines_count; i++) {
    x0 = lines[i][0];
    y0 = lines[i][1];
    x1 = lines[i][2];
    y1 = lines[i][3];
    cohen_sutherland_line_clip(x0, y0, x1, y1, xmin, xmax, ymin, ymax);
  }

  getch();
  return 0;
}

