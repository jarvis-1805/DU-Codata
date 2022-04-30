/**
 * @file main.cpp
 * @author Shubhang Gupta (https://github.com/jarvis-1805)
 * @brief Implementation to perform Scaling, Reflection, Rotation, Shearing, Translation of a 2D-Object.
 * @version 0.1
 * @date 2022-02-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#undef __STRICT_ANSI__
#include <cmath>
#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <cstdlib>
#include <vector>

using namespace std;

class transformation {
  private:
    int x0 = 0;
    int y0 = 0;
    int _vertices = 0;
    vector<vector<int> > _figure;

    vector<vector<int> > matrix_multiply(vector<vector<int> > &, vector<vector<int> > &);
    void translated_axis(int, int);
    void original_figure();
    void transformed_figure(vector<vector<int> > &);
  
  public:
    transformation(int, vector<vector<int> > &);
    ~transformation();

    void scale();
    void reflect();
    void rotate();
    void shear();
    void translate();
};

transformation::transformation(int _vertices, vector<vector<int> > &_figure) {
  this -> _vertices = _vertices;
  this -> _figure = _figure;

  int gd = DETECT, gm, max_x, max_y;
  initgraph(&gd, &gm, (char*)"");

  max_x = getmaxx();
  max_y = getmaxy();

  this -> x0 = max_x / 2;
  this -> y0 = max_y / 2;

  translated_axis(max_x, max_y);
  original_figure();
}

transformation::~transformation() {
  closegraph();
}

void transformation::translated_axis(int max_x, int max_y) {
  setcolor(WHITE);
  line(0, max_y/2, max_x, max_y/2);
  line(max_x/2, 0, max_x/2, max_y);
}

vector<vector<int> > transformation::matrix_multiply(vector<vector<int> > & _matrix1, vector<vector<int> > & _matrix2) {
  int rows = _vertices;
  vector<vector<int> > _temp(rows, vector<int> (3, 0));
  vector<vector<int> > resultant_matrix(rows, vector<int> (3, 0));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < 3; j++) {
      _temp[i][j] = 0;
      for (int k = 0; k < 3; k++) {
        _temp[i][j] += _matrix1[i][k] * _matrix2[k][j];
      }
      resultant_matrix[i][j] = _temp[i][j];
    }
  }

  return resultant_matrix;
}

void transformation::original_figure() {
  int i;
  int x1 = _figure[0][0];
  int y1 = _figure[0][1];
  setcolor(WHITE);
  
  for (i = 0; i < _vertices - 1; i++) {
    line(x0 + _figure[i][0], y0 - _figure[i][1], x0 + _figure[i+1][0], y0 - _figure[i+1][1]);
  }
  
  int x2 = _figure[i][0];
  int y2 = _figure[i][1];
  line(x0 + x1, y0 - y1, x0 + x2, y0 - y2);
}

void transformation::transformed_figure(vector<vector<int> > &_figure) {
  int i;
  int x1 = _figure[0][0];
  int y1 = _figure[0][1];
  setcolor(RED);
  
  for (i = 0; i < _vertices - 1; i++) {
    line(x0 + _figure[i][0], y0 - _figure[i][1], x0 + _figure[i+1][0], y0 - _figure[i+1][1]);
  }
  
  int x2 = _figure[i][0];
  int y2 = _figure[i][1];
  line(x0 + x1, y0 - y1, x0 + x2, y0 - y2);

  cout << "\nPress Enter to continue...";
  cin.ignore();
  getchar();
  cleardevice();

  translated_axis(x0*2, y0*2);
  original_figure();
}

void transformation::scale() {
  int scale_choice;
  int x = 1, y = 1, S = 1;
  vector<vector<int> > scaled_figure;
  vector<vector<int> > scaling_matrix { {x, 0, 0},
                                        {0, y, 0},
                                        {0, 0, S} };
  do {
    system("clear");
    cout << "\n----- Scaling Menu -----"
        << "\n1. Scale through X-Coordinate"
        << "\n2. Scale through Y-Coordinate"
        << "\n3. Scale through XY-Coordinate"
        << "\n4. Overall Scaling"
        << "\n0. Exit"
        << "\n\nEnter the choice : ";
    cin >> scale_choice;

    switch (scale_choice) {
      case 1:
        cout << "\nEnter X-factor: ";
        cin >> x;
        scaling_matrix[0][0] = x;
        scaled_figure = matrix_multiply(_figure, scaling_matrix);
        break;
      
      case 2:
        cout << "\nEnter Y-factor: ";
        cin >> y;
        scaling_matrix[1][1] = y;
        scaled_figure = matrix_multiply(_figure, scaling_matrix);
        break;
        
      case 3:
        cout << "\nEnter XY-factor: ";
        cin >> x >> y;
        scaling_matrix[0][0] = x;
        scaling_matrix[1][1] = y;
        scaled_figure = matrix_multiply(_figure, scaling_matrix);
        break;
      
      case 4:
        cout << "\nEnter S-factor: ";
        cin >> S;
        scaling_matrix[2][2] = S;
        scaled_figure = matrix_multiply(_figure, scaling_matrix);
        
        // Normalization
        S = scaled_figure[0][2];
        for (int i = 0; i < _vertices; i++) {
          scaled_figure[i][0] /= S;
          scaled_figure[i][1] /= S;
        }
        break;
      
      case 0:
        return;
        break;
      
      default:
        cout << "\nInvalid Choice!!! Try again!!!";
        break;
    }
    
    transformed_figure(scaled_figure);
  } while (scale_choice != 0);
}

void transformation::reflect() {
  int reflect_choice;
  int a = 0, b = 0, c = 0, d = 0;
  vector<vector<int> > reflected_figure;
  vector<vector<int> > reflecting_matrix { {a, b, 0},
                                           {c, d, 0},
                                           {0, 0, 1} };
  
  do {
    system("clear");
    cout << "\n----- Reflecting Menu -----"
        << "\n1. Reflect about X-Axis (y=0)"
        << "\n2. Reflect about Y-Axis (x=0)"
        << "\n3. Reflect about line y = x"
        << "\n4. Reflect about line y = -x"
        << "\n0. Exit"
        << "\n\nEnter the choice : ";
    cin >> reflect_choice;

    switch (reflect_choice) {
      case 1:
        a = 1;
        b = 0;
        c = 0;
        d = -1;
        break;
      
      case 2:
        a = -1;
        b = 0;
        c = 0;
        d = 1;
        break;
          
      case 3:
        a = 0;
        b = 1;
        c = 1;
        d = 0;
        break;
      
      case 4:
        a = 0;
        b = -1;
        c = -1;
        d = 0;
        break;
      
      case 0:
        return;
        break;
      
      default:
        cout << "\nInvalid Choice!!! Try again!!!";
        break;
    }

    reflecting_matrix[0][0] = a;
    reflecting_matrix[0][1] = b;
    reflecting_matrix[1][0] = c;
    reflecting_matrix[1][1] = d;
    reflected_figure = matrix_multiply(_figure, reflecting_matrix);
    transformed_figure(reflected_figure);
  } while (reflect_choice != 0);
}

void transformation::rotate() {
  int rotate_choice;
  int _sin = 1, _cos = 1;
  int _theta = 0;
  vector<vector<int> > rotated_figure;
  vector<vector<int> > rotating_matrix { { _cos, _sin, 0},
                                         {-_sin, _cos, 0},
                                         {    0,    0, 1} };
  do {
    system("clear");
    cout << "\n----- Rotating Menu -----"
        << "\n1. Rotating Clockwise"
        << "\n2. Rotating Anti-Clockwise"
        << "\n0. Exit"
        << "\n\nEnter the choice : ";
    cin >> rotate_choice;

    switch (rotate_choice) {
      case 1:
        cout << "\nEnter the angle (theta): ";
        cin >> _theta;
        _theta = -_theta;
        break;
        
      case 2:
        cout << "\nEnter the angle (theta): ";
        cin >> _theta;
        _theta = +_theta;
        break;

      case 0:
        return;
        break;

      default:
        cout << "\nInvalid Choice!!! Try again!!!";
        break;
    }

    _cos = cos(_theta * M_PI / 180);
    _sin = sin(_theta * M_PI / 180);

    rotating_matrix[0][0] = _cos;
    rotating_matrix[0][1] = _sin;
    rotating_matrix[1][0] = -_sin;
    rotating_matrix[1][1] = _cos;
    rotated_figure = matrix_multiply(_figure, rotating_matrix);
    transformed_figure(rotated_figure);
  } while (rotate_choice != 0);
}

void transformation::shear() {
  int shear_choice;
  int b = 0, c = 0;
  vector<vector<int> > sheared_figure;
  vector<vector<int> > shearing_matrix { {1, b, 0},
                                         {c, 1, 0},
                                         {0, 0, 1} };
  do {
    system("clear");
    cout << "\n----- Shearing Menu -----"
        << "\n1. Shearing along x-axis"
        << "\n1. Shearing along y-axis"
        << "\n3. Shearing along both x and y axis"
        << "\n0. Exit"
        << "\n\nEnter the choice : ";
    cin >> shear_choice;

    switch (shear_choice) {
      case 1:
        cout << "\nEnter the shearing factor: ";
        cin >> c;
        break;
      
      case 2:
        cout << "\nEnter the shearing factor: ";
        cin >> b;
        break;

      case 3:
        cout << "\nEnter the shearing factor [x y]: ";
        cin >> c >> b;
        break;

      case 0:
        return;
        break;

      default:
        cout << "\nInvalid Choice!!! Try again!!!";
        break;
      }

      shearing_matrix[0][1] = b;
      shearing_matrix[1][0] = c;
      sheared_figure = matrix_multiply(_figure, shearing_matrix);
      transformed_figure(sheared_figure);
  } while (shear_choice != 0);
}

void transformation::translate() {
  int translate_choice;
  int m = 0, n = 0;
  vector<vector<int> > translated_figure;
  vector<vector<int> > translating_matrix { {1, 0, 0},
                                            {0, 1, 0},
                                            {m, n, 1} };
  do {
    system("clear");
    cout << "\n----- Translating Menu -----"
        << "\n1. Translate along x direction"
        << "\n2. Translate along y direction"
        << "\n3. Translate along x and y direction"
        << "\n0. Exit"
        << "\n\nEnter the choice : ";
    cin >> translate_choice;

    switch (translate_choice) {
      case 1:
        cout << "\nEnter the translation factor: ";
        cin >> m;
        break;
      
      case 2:
        cout << "\nEnter the translation factor: ";
        cin >> n;
        break;
          
      case 3:
        cout << "\nEnter the translation factor [x y]: ";
        cin >> m >> n;
        break;

      case 0:
        return;
        break;

      default:
        cout << "\nInvalid Choice!!! Try again!!!";
        break;
    }

    translating_matrix[2][0] = m;
    translating_matrix[2][1] = n;
    translated_figure = matrix_multiply(_figure, translating_matrix);
    transformed_figure(translated_figure);
  } while (translate_choice != 0);
}

int main(void) {
  int _vertices=0, _choice=0, _x, _y;
  
  system("clear");
  cout << "\n----- 2D Transformation -----\n";

  cout << "\nEnter the no. of vertices in 2D figure: ";
  cin >> _vertices;

  vector<vector<int> > _figure;
  vector<int> _vertex;
  
  cout << "\nEnter the co-ordinates:\n";
  for (int i = 0; i < _vertices; i++) {
    cout << "Enter the vertex " << i+1 << ": ";
    cin >> _x >> _y;
    _vertex.push_back(_x);
    _vertex.push_back(_y);
    _vertex.push_back(1);
    _figure.push_back(_vertex);
    _vertex.clear();
  }

  transformation transform(_vertices, _figure);
  
  do {
    system("clear");
    cout << "\n---------- Transformation Menu ----------"
        << "\n1. Scaling"
        << "\n2. Reflection"
        << "\n3. Rotation"
        << "\n4. Shearing"
        << "\n5. Translation"
        << "\n0. Exit"
        << "\n\nEnter choice: ";
    cin >> _choice;

    switch (_choice) {
      case 1:
        transform.scale();
        break;

      case 2:
        transform.reflect();
        break;
      
      case 3:
        transform.rotate();
        break;
      
      case 4:
        transform.shear();
        break;
      
      case 5:
        transform.translate();
        break;
      
      case 0:
        break;

      default:
        cout << "\nWARNING!!! Enter a valid choice!!!";
        break;
    }
  } while (_choice != 0);

  return 0;
}
