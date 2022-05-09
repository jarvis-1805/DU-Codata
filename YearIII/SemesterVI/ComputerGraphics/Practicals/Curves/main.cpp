/**
 * @file main.cpp
 * @author Shubhang Gupta (https://github.com/jarvis-1805)
 * @brief Write a program to draw Hermite / Bezier curve.
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 4

void hermite_curve(vector<vector<int> > &_controlPoints) {
  int _x, _y, _x1, _y1;
  
  setcolor(BLACK);
  for (int i = 0; i < MAX; i++) {
    _x = _controlPoints[i][0];
    _y = _controlPoints[i][1];
    putpixel(_x, _y, BLACK);
    circle(_x, _y, 5);
  }

  setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
  setcolor(RED);
  for (int i = 0; i < MAX - 2; i++) {
    _x = _controlPoints[i][0];
    _y = _controlPoints[i][1];
    _x1 = _controlPoints[i+2][0];
    _y1 = _controlPoints[i+2][1];
    line(_x, _y, _x1, _y1);
  }

  for (float t = 0; t <= 1; t += 0.0001) {
    _x = (2*pow(t, 3) - 3*pow(t, 2) + 1)*_controlPoints[0][0]
          + (-2*pow(t, 3) + 3*pow(t, 2))*_controlPoints[1][0]
          + (pow(t, 3) - 2*pow(t, 2) + t)*_controlPoints[2][0]
          + (pow(t, 3) - pow(t, 2))*_controlPoints[3][0];
    
    _y = (2*pow(t, 3) - 3*pow(t, 2) + 1)*_controlPoints[0][1]
          + (-2*pow(t, 3) + 3*pow(t, 2))*_controlPoints[1][1]
          + (pow(t, 3) - 2*pow(t, 2) + t)*_controlPoints[2][1]
          + (pow(t, 3) - pow(t, 2))*_controlPoints[3][1];;

    putpixel(_x, _y, BLACK);
    for (int i=0; i<=10e4; i++);
  }
}

void bezier_curve(vector<vector<int> > &_controlPoints) {
  int _x, _y, _x1, _y1;
  
  setcolor(BLACK);
  for (int i = 0; i < MAX; i++) {
    _x = _controlPoints[i][0];
    _y = _controlPoints[i][1];
    putpixel(_x, _y, BLACK);
    circle(_x, _y, 5);
  }

  setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
  setcolor(RED);
  for (int i = 0; i < MAX - 1; i++) {
    _x = _controlPoints[i][0];
    _y = _controlPoints[i][1];
    _x1 = _controlPoints[i+1][0];
    _y1 = _controlPoints[i+1][1];
    line(_x, _y, _x1, _y1);
  }
  // B(t) = (1-t)^3P0 + 3(1-t)^2tP1 + 3(1-t)^2t^2P2 + t^3P3
  for (float t = 0; t <= 1; t += 0.0001) {
    _x = pow(t, 3)*(_controlPoints[3][0] + 3*(_controlPoints[1][0] - _controlPoints[2][0]) - _controlPoints[0][0])
          + 3*pow(t, 2)*(_controlPoints[0][0] - 2*_controlPoints[1][0] + _controlPoints[2][0])
          + 3*t*(_controlPoints[1][0] - _controlPoints[0][0])
          + _controlPoints[0][0];
    
    _y = pow(t, 3)*(_controlPoints[3][1] + 3*(_controlPoints[1][1] - _controlPoints[2][1]) - _controlPoints[0][1])
          + 3*pow(t, 2)*(_controlPoints[0][1] - 2*_controlPoints[1][1] + _controlPoints[2][1])
          + 3*t*(_controlPoints[1][1] - _controlPoints[0][1])
          + _controlPoints[0][1];
    
    putpixel(_x, _y, BLACK);
    for (int i=0; i<=10e4; i++);
  }
}

vector<vector<int> > input_control_points() {  
  int x, y;
  vector<vector<int> > controlPoints;
  vector<int> point;

  for (int i = 0; i < MAX; i++) {
      cout << "Enter the control point " << i+1 << " (x, y) : ";
      cin >> x >> y;
      point.push_back(x);
      point.push_back(y);

      controlPoints.push_back(point);
      point.clear();
    }

    //The entered co-ordinates of ponts
    // for (int i = 0; i < MAX; i++) {
    //   for (int j = 0; j < 2; j++) {
    //     cout << controlPoints[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    return controlPoints;
}

int main() {
	cout << "\n============ HERMITE AND BEZIER CURVE ============\n";

  int curveChoice;
  vector<vector<int> > controlPoints;

  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  setbkcolor(WHITE);
  
  curve_menu:
    cleardevice();
    cout << "\n===== MENU ====="
          << "\n1. Hermite Curve"
          << "\n2. Bezier Curve"
          << "\n0. Exit" << endl;
    cout << "\nEnter your choice : ";
    cin >> curveChoice;

    switch (curveChoice) {
      case 1:
        cout << "\n====== Hermite Curve ======\n";
        controlPoints = input_control_points();
        hermite_curve(controlPoints);
        break;

      case 2:
        cout << "\n===== Bezier Curve =====\n";
        controlPoints = input_control_points();
        bezier_curve(controlPoints);
        break;
      
      case 0:
        cout << "\nExiting...\n";
        exit(0);
      
      default:
        cout << "\nINVALID CHOICE... TRY AGAIN!!!";
        break;
    }
  
  delay(10e3);
  goto curve_menu;

  getch();
  return 0;
}

