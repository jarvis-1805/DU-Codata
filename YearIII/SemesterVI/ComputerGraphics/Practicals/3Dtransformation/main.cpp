/**
 * @file main.cpp
 * @author Shubhang Gupta
 * @brief Implementation of 3-D transformation
 * @version 0.1
 * @date 2022-02-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#undef __STRICT_ANSI__
#include <cmath>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "projection.hpp"

using namespace std;

class transformation {
  private:
    int x0, y0;
    int _vertices = 0;
    vector<vector<double> > _figure;

    vector<vector<double> > matrix_multiply(vector<vector<double> > &, vector<vector<double> > &);
    void translated_axis(int, int);
    void transformed_figure(vector<vector<double> > &);
  
  public:
    transformation(int, vector<vector<double> > &);
    ~transformation();

    void scale();
    void translate();
    void rotate();
    void shear();
    void reflect();
};

transformation::transformation(int _vertices, vector<vector<double> > &_figure) {
  this -> _vertices = _vertices;
  this -> _figure = _figure;

  int gd = DETECT, gm;
  initgraph(&gd, &gm, (char*)"");

  int max_x = getmaxx();
  int max_y = getmaxy();

  this -> x0 = max_x / 2;
  this -> y0 = max_y / 2;

  translated_axis(max_x, max_y);

  line(0, max_y/2, max_x, max_y/2);
  line(max_x/2, 0, max_x/2, max_y);
}

transformation::~transformation() {
  closegraph();
}

void transformation::translated_axis(int max_x, int max_y) {
  setcolor(WHITE);
  line(0, max_y/2, max_x, max_y/2);
  line(max_x/2, 0, max_x/2, max_y);
}

vector<vector<double> > transformation::matrix_multiply(vector<vector<double> > & _matrix1, vector<vector<double> > & _matrix2) {
  int rows = _vertices;
  vector<vector<double> > _temp(rows, vector<double> (4, 0));
  vector<vector<double> > resultant_matrix(rows, vector<double> (4, 0));
  
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < 4; j++) {
      _temp[i][j] = 0;
      for (int k = 0; k < 4; k++) {
        _temp[i][j] += _matrix1[i][k] * _matrix2[k][j];
      }
      resultant_matrix[i][j] = _temp[i][j];
    }
  }
  
  return resultant_matrix;
}

void transformation::transformed_figure(vector<vector<double> > &_figure) {
  
  cout << "\nTransformed Figure :\n";


  for (int i = 0; i < _vertices; i++) {
    for (int j = 0; j < 4; j++) {
      cout << _figure[i][j] << " ";
    }
    cout << endl;
  }

  projection project(x0, y0);
  project.projection_menu(_figure);
}

void transformation::scale() {
  int scale_choice;
  double x = 1, y = 1, z = 1, S = 1;
  vector<vector<double> > scaled_figure;
  vector<vector<double> > scaling_matrix { {x, 0, 0, 0},
                                           {0, y, 0, 0},
                                           {0, 0, z, 0},
                                           {0, 0, 0, S} };
  do {
    cout << "\n----- Scaling Menu -----"
        << "\n1. Local Scaling"
        << "\n2. Overall Scaling"
        << "\n0. Exit"
        << "\n\nEnter the choice : ";
    cin >> scale_choice;

    switch (scale_choice) {
      case 1:
        cout << "\nEnter XYZ-factor: ";
        cin >> x >> y >> z;
        scaling_matrix[0][0] = x;
        scaling_matrix[1][1] = y;
        scaling_matrix[2][2] = z;
        scaled_figure = matrix_multiply(_figure, scaling_matrix);
        transformed_figure(scaled_figure);
        break;

      case 2:
        cout << "\nEnter S-factor: ";
        cin >> S;
        scaling_matrix[3][3] = 1 / S;
        scaled_figure = matrix_multiply(_figure, scaling_matrix);
        
        // Normalization
        cout << "\nNormalizing...\n";
        S = scaled_figure[0][3];
        for (int i = 0; i < _vertices; i++) {
          scaled_figure[i][0] = scaled_figure[i][0] / S;
          scaled_figure[i][1] = scaled_figure[i][1] / S;
          scaled_figure[i][2] = scaled_figure[i][2] / S;
          scaled_figure[i][3] = scaled_figure[i][3] / S;
        }
        transformed_figure(scaled_figure);
        break;
      
      case 0:
        this -> ~transformation();
        break;
      
      default:
        cout << "\nInvalid Choice!!! Try again!!!";
        break;
    }
  } while (scale_choice != 0);
}

void transformation::translate() {
  int translate_choice;
  double l = 0, m = 0, n = 0;
  vector<vector<double> > translated_figure;
  vector<vector<double> > translating_matrix { {1, 0, 0, 0},
                                               {0, 1, 0, 0},
                                               {0, 0, 1, 0},
                                               {l, m, n, 1} };
                                               
  cout << "\n----- Translating -----";

  cout << "\nEnter the XYZ-direction: ";
  cin >> l >> m >> n;
  translating_matrix[3][0] = l;
  translating_matrix[3][1] = m;
  translating_matrix[3][2] = n;
  translated_figure = matrix_multiply(_figure, translating_matrix);
  transformed_figure(translated_figure);
}

void transformation::rotate() {
  int rotate_choice;
  double _sin = 1, _cos = 1;
  int _theta = 0;
  vector<vector<double> > rotated_figure;
  vector<vector<double> > rotating_matrix_x { {1,     0,    0, 0},
                                              {0,  _cos, _sin, 0},
                                              {0, -_sin, _cos, 0},
                                              {0,     0,    0, 1} };

  vector<vector<double> > rotating_matrix_y { { _cos, 0, -_sin, 0},
                                              {    0, 1,     0, 0},
                                              { _sin, 0,  _cos, 0},
                                              {    0, 0,     0, 1} };

  vector<vector<double> > rotating_matrix_z { { _cos, _sin, 0, 0},
                                              {-_sin, _cos, 0, 0},
                                              {    0,    0, 1, 0},
                                              {    0,    0, 0, 1} };

  do {
    cout << "\n----- Rotating Menu -----"
        << "\n1. Rotating along X-axis"
        << "\n2. Rotating along Y-axis"
        << "\n3. Rotating along Z-axis"
        << "\n0. Exit"
        << "\n\nEnter the choice : ";
    cin >> rotate_choice;

    switch (rotate_choice) {
      case 1:
        cout << "\nEnter the angle (theta): ";
        cin >> _theta;

        _cos = cos(_theta * M_PI / 180);
        _sin = sin(_theta * M_PI / 180);

        rotating_matrix_x[1][1] = _cos;
        rotating_matrix_x[1][2] = _sin;
        rotating_matrix_x[2][1] = -_sin;
        rotating_matrix_x[2][2] = _cos;

        rotated_figure = matrix_multiply(_figure, rotating_matrix_x);
        transformed_figure(rotated_figure);
        break;
        
      case 2:
        cout << "\nEnter the angle (theta): ";
        cin >> _theta;

        _cos = cos(_theta * M_PI / 180);
        _sin = sin(_theta * M_PI / 180);

        rotating_matrix_y[0][0] = _cos;
        rotating_matrix_y[0][1] = _sin;
        rotating_matrix_y[1][0] = -_sin;
        rotating_matrix_y[1][1] = _cos;

        rotated_figure = matrix_multiply(_figure, rotating_matrix_y);
        transformed_figure(rotated_figure);
        break;

      case 3:
        cout << "\nEnter the angle (theta): ";
        cin >> _theta;

        _cos = cos(_theta * M_PI / 180);
        _sin = sin(_theta * M_PI / 180);

        rotating_matrix_z[0][0] = _cos;
        rotating_matrix_z[0][2] = -_sin;
        rotating_matrix_z[2][0] = _sin;
        rotating_matrix_z[2][2] = _cos;

        rotated_figure = matrix_multiply(_figure, rotating_matrix_z);
        transformed_figure(rotated_figure);
        break;

      case 0:
        this -> ~transformation();
        break;

      default:
        cout << "\nInvalid Choice!!! Try again!!!";
        break;
    }
  } while (rotate_choice != 0);
}

void transformation::shear() {
  int shear_choice;
  double b = 0, c = 0, d = 0, f = 0, g = 0, i = 0;
  vector<vector<double> > sheared_figure;
  vector<vector<double> > shearing_matrix { {1, b, c, 0},
                                            {d, 1, f, 0},
                                            {g, i, 1, 0},
                                            {0, 0, 0, 1} };

  cout << "\nEnter the shearing factors [b c d f g i]: ";
  cin >> b >> c >> d >> f >> g >> i;

  shearing_matrix[0][1] = b;
  shearing_matrix[0][2] = c;
  shearing_matrix[1][0] = d;
  shearing_matrix[1][2] = f;
  shearing_matrix[2][0] = g;
  shearing_matrix[2][1] = i;

  sheared_figure = matrix_multiply(_figure, shearing_matrix);
  transformed_figure(sheared_figure);
}

void transformation::reflect() {
  int reflect_choice;
  double a = 1, e = 1, j = 1;
  vector<vector<double> > reflected_figure;
  vector<vector<double> > reflecting_matrix { {a, 0, 0, 0},
                                              {0, e, 0, 0},
                                              {0, 0, j, 0},
                                              {0, 0, 0, 1} };
  
  do {
    cout << "\n----- Reflecting Menu -----"
        << "\n1. Reflect about XY-plane"
        << "\n2. Reflect about YZ-plane"
        << "\n3. Reflect about XZ-plane"
        << "\n0. Exit"
        << "\n\nEnter the choice : ";
    cin >> reflect_choice;

    switch (reflect_choice) {
      case 1:
        a = 1;
        e = 1;
        j = -1;
        break;
      
      case 2:
        a = -1;
        e = 1;
        j = 1;
        break;
          
      case 3:
        a = 1;
        e = -1;
        j = 1;
        break;

      case 0:
        this -> ~transformation();
        break;
      
      default:
        cout << "\nInvalid Choice!!! Try again!!!";
        break;
    }

    reflecting_matrix[0][0] = a;
    reflecting_matrix[1][1] = e;
    reflecting_matrix[2][2] = j;
    reflected_figure = matrix_multiply(_figure, reflecting_matrix);
    transformed_figure(reflected_figure);
  } while (reflect_choice != 0);
}

int main(void) {
  int _choice = 0;
  int _vertices = 8;
  int _x, _y, _z;
  vector<vector<double> > _figure;
  vector<int> _vertex;

  // (0, 0, 0), (1, 0, 0), (1, 1, 0), (0, 1, 0),
  // (0, 0, 1), (1, 0, 1), (1, 1, 1), (0, 1, 1)
  
  // cout << "\nEnter the number of vertices: ";
  // cin >> _vertices;

  // for (int i = 0; i < _vertices; i++) {
  //   cout << "\nEnter the vertex " << i << ": ";
  //   cin >> _x >> _y >> _z;
  //   _vertex.push_back(_x);
  //   _vertex.push_back(_y);
  //   _vertex.push_back(_z);
  //   _vertex.push_back(1);
  //   _figure.push_back(_vertex);
  //   _vertex.clear();
  // }

  _figure = {
    {0, 0, 50, 1},
    {100, 0, 50, 1},
    {100, 150, 50, 1},
    {0, 150, 50, 1},
    {0, 0, 0, 1},
    {100, 0, 0, 1},
    {100, 150, 0, 1},
    {0, 150, 0, 1},
  };

  // _figure = {
  //   {0, 0, 1, 1},
  //   {2, 0, 1, 1},
  //   {2, 3, 1, 1},
  //   {0, 3, 1, 1},
  //   {0, 0, 0, 1},
  //   {2, 0, 0, 1},
  //   {2, 3, 0, 1},
  //   {0, 3, 0, 1},
  // };
  
  // _figure = {
  //   {0, 0, 1, 1},
  //   {1, 0, 1, 1},
  //   {1, 1, 1, 1},
  //   {0, 1, 1, 1},
  //   {0, 0, 0, 1},
  //   {1, 0, 0, 1},
  //   {1, 1, 0, 1},
  //   {0, 1, 0, 1},
  // };
  
  // _figure = {
  //   {1, 0, -1, 1},
  //   {2, 0, -1, 1},
  //   {2, 1, -1, 1},
  //   {1, 1, -1, 1},
  //   {1, 0, -2, 1},
  //   {2, 0, -2, 1},
  //   {2, 1, -2, 1},
  //   {1, 1, -2, 1},
  // };

  do {
    cout << "\n-------- 3-D Menu --------"
        << "\n1. Scaling"
        << "\n2. Translation"
        << "\n3. Rotation"
        << "\n4. Shearing"
        << "\n5. Reflection"
        << "\n0. Exit"
        << "\nEnter your choice: ";
    
    cin >> _choice;

    transformation transform(_vertices, _figure);
    switch (_choice) {
      case 1:
        transform.scale();
        break;

      case 2:
        transform.translate();
        break;

      case 3:
        transform.rotate();
        break;

      case 4:
        transform.shear();
        break;

      case 5:
        transform.reflect();
        break;

      case 0:
        transform.~transformation();
        exit(0);
        break;
      
      default:
        cout << "\nInvalid Chocice!!!";
        break;
    }
  } while (1);

  getch();
  return 0;
}

