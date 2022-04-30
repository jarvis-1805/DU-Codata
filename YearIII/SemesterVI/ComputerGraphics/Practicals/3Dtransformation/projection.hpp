#pragma once

#include <vector>
#include <iostream>

class projection {
  private:
    int x0, y0;
    char projection_axis = 'z';

    std::vector<std::vector<double> > matrix_multiply(std::vector<std::vector<double> > &, std::vector<std::vector<double> > &);
    void display_projection(std::vector<std::vector<double> > &);
    
  public:
    projection(int, int);
    ~projection();

    void projection_menu(std::vector<std::vector<double> > &);
    std::vector<std::vector<double> > orthographic_projection(std::vector<std::vector<double> > &);
    std::vector<std::vector<double> > axonometric_projection(std::vector<std::vector<double> > &);
    std::vector<std::vector<double> > perspective_projection(std::vector<std::vector<double> > &);
};

projection::projection(int _x0, int _y0) {
  this -> x0 = _x0;
  this -> y0 = _y0;
}

projection::~projection() {

}

std::vector<std::vector<double> > projection::matrix_multiply(std::vector<std::vector<double> > &_matrix1, std::vector<std::vector<double> > &_matrix2) {
  int rows = _matrix1.size();
  std::vector<std::vector<double> > _temp(rows, std::vector<double> (4, 0));
  std::vector<std::vector<double> > resultant_matrix(rows, std::vector<double> (4, 0));
  
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

void projection::display_projection(std::vector<std::vector<double> > &_projected_figure) {
  std::cout << "\nProjected Figure : \n";
  int _rows = _projected_figure.size();
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < 4; j++) {
      std::cout << _projected_figure[i][j] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "\nDisplay Projection...\n";
  
  int display_figure[_rows][2];
  int i;

  if (projection_axis == 'z') {
    for (i = 0; i < _rows; i++) {
        display_figure[i][0] = this -> x0 + _projected_figure[i][0];
        display_figure[i][1] = this -> y0 - _projected_figure[i][1];
    }
  }
  
  if (projection_axis == 'y') {
    for (i = 0; i < _rows; i++) {
        display_figure[i][0] = this -> x0 + _projected_figure[i][0];
        display_figure[i][1] = this -> y0 - _projected_figure[i][2];
    }
  }

  if (projection_axis == 'x') {
    for (i = 0; i < _rows; i++) {
        display_figure[i][0] = this -> x0 + _projected_figure[i][1];
        display_figure[i][1] = this -> y0 - _projected_figure[i][2];
    }
  }

  std::cout << "\n Printing Display Figure...\n";
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < 2; j++) {
      std::cout << display_figure[i][j] << " ";
    }
    std::cout << std::endl;
  }

  setcolor(RED);
  
  for (i = 0; i < _rows/2 - 1; i++) {
    line(x0 + _projected_figure[i][0], y0 - _projected_figure[i][1], x0 + _projected_figure[i+1][0], y0 - _projected_figure[i+1][1]);
    line(x0 + _projected_figure[i+4][0], y0 - _projected_figure[i+4][1], x0 + _projected_figure[i+4+1][0], y0 - _projected_figure[i+4+1][1]);
    line(x0 + _projected_figure[i][0], y0 - _projected_figure[i][1], x0 + _projected_figure[i+4][0], y0 - _projected_figure[i+4][1]);
  }

  line(x0 + _projected_figure[i][0], y0 - _projected_figure[i][1], x0 + _projected_figure[i+4][0], y0 - _projected_figure[i+4][1]);
  line(x0 + _projected_figure[0][0], y0 - _projected_figure[0][1], x0 + _projected_figure[i][0], y0 - _projected_figure[i][1]);
  line(x0 + _projected_figure[4][0], y0 - _projected_figure[4][1], x0 + _projected_figure[_rows-1][0], y0 - _projected_figure[_rows-1][1]);
}

void projection::projection_menu(std::vector<std::vector<double> > &_transformed_figure) {
  int projection_choice;
  std::vector<std::vector<double> > projected_figure;
  std::cout << "\n----- Projection Menu -----"
            << "\n1. Orthographic Projection"
            << "\n2. Axonometric Projection"
            << "\n3. Perspective Projection"
            << "\n0. Exit"
            << "\n\nEnter the choice : ";
  std::cin >> projection_choice;

  switch (projection_choice) {
    case 1:
      projected_figure = orthographic_projection(_transformed_figure);
      display_projection(projected_figure);
      break;
    
    case 2:
      projected_figure = axonometric_projection(_transformed_figure);
      display_projection(projected_figure);
      break;

    case 3:
      projected_figure = perspective_projection(_transformed_figure);
      display_projection(projected_figure);
      break;

    case 0:
      exit(0);

    default:
      std::cout << "\nInvalid Choice!!! Try again!!!";
      exit(0);
      break;
  }
}

std::vector<std::vector<double> > projection::orthographic_projection(std::vector<std::vector<double> > &_transformed_figure) {
  int orthographic_projection_choice;
  double x=1, y=1, z=1;

  std::vector<std::vector<double> > projected_figure;
  std::vector<std::vector<double> > orthographic_projection_matrix { {x, 0, 0, 0},
                                                                     {0, y, 0, 0},
                                                                     {0, 0, z, 0},
                                                                     {0, 0, 0, 1} };

  std::cout << "\n----- Orthographic Projection Menu -----"
            << "\n1. Projection onto X = 0 plane"
            << "\n2. Projection onto Y = 0 plane"
            << "\n3. Projection onto Z = 0 plane"
            << "\n0. Exit"
            << "\n\nEnter the choice : ";
  std::cin >> orthographic_projection_choice;

  switch (orthographic_projection_choice) {
    case 1:
      x = 0;
      projection_axis = 'x';
      break;
    
    case 2:
      y = 0;
      projection_axis = 'y';
      break;
    
    case 3:
      z = 0;
      projection_axis = 'z';
      break;

    case 0:
      exit(0);

    default:
      std::cout << "\nInvalid Choice!!! Try again!!!";
      exit(0);
      break;
  }

  orthographic_projection_matrix[0][0] = x;
  orthographic_projection_matrix[1][1] = y;
  orthographic_projection_matrix[2][2] = z;
  projected_figure = matrix_multiply(_transformed_figure, orthographic_projection_matrix);

  return projected_figure;
}

std::vector<std::vector<double> > projection::axonometric_projection(std::vector<std::vector<double> > &_transformed_figure) {
  int axonometric_projection_choice;
  double x=1, y=1, z=0;
  float _theta, _phi;
  double _sin_theta = 1, _cos_theta = 1, _sin_phi = 1, _cos_phi = 1;

  std::vector<std::vector<double> > projected_figure;
  std::vector<std::vector<double> > x_rotation_matrix, y_rotation_matrix, z_ortho_matrix;
  std::vector<std::vector<double> > axonometric_projection_matrix;

  x_rotation_matrix = { {1,           0,          0, 0},
                        {0,  _cos_theta, _sin_theta, 0},
                        {0, -_sin_theta, _cos_theta, 0},
                        {0,           0,          0, 1} };

  y_rotation_matrix = { { _cos_phi, 0, -_sin_phi, 0},
                        {        0, 1,         0, 0},
                        { _sin_phi, 0,  _cos_phi, 0},
                        {        0, 0,         0, 1} };

  z_ortho_matrix = { {x, 0, 0, 0},
                     {0, y, 0, 0},
                     {0, 0, z, 0},
                     {0, 0, 0, 1} };

  std::cout << "\n----- Axonometric Projection Menu -----"
            << "\n1. Trimetric Axonometric Projection"
            << "\n2. Dimetric Axonometric Projection"
            << "\n3. Isometric Axonometric Projection"
            << "\n0. Exit"
            << "\n\nEnter the choice : ";
  std::cin >> axonometric_projection_choice;

  switch (axonometric_projection_choice) {
    case 1:
      std::cout << "\nEnter the angle (theta) along x-axis: ";
      std::cin >> _theta;
      std::cout << "\nEnter the angle (phi) along y-axis: ";
      std::cin >> _phi;
      
      _cos_theta = cos(_theta * M_PI / 180);
      _sin_theta = sin(_theta * M_PI / 180);
      
      _cos_phi = cos(_phi * M_PI / 180);
      _sin_phi = sin(_phi * M_PI / 180);

      x_rotation_matrix[1][1] = _cos_theta;
      x_rotation_matrix[1][2] = _sin_theta;
      x_rotation_matrix[2][1] = _cos_theta;
      x_rotation_matrix[2][2] = -_sin_theta;

      y_rotation_matrix[0][0] = _cos_phi;
      y_rotation_matrix[0][2] = -_sin_phi;
      y_rotation_matrix[2][1] = _sin_phi;
      y_rotation_matrix[2][2] = _cos_phi;

      axonometric_projection_matrix = matrix_multiply(x_rotation_matrix, y_rotation_matrix);
      break;
    
    case 2:
      std::cout << "\nEnter the angle (phi) along y-axis: ";
      std::cin >> _theta;
      std::cout << "\nEnter the angle (theta) along x-axis: ";
      std::cin >> _phi;

      _cos_phi = cos(_phi * M_PI / 180);
      _sin_phi = sin(_phi * M_PI / 180);

      _cos_theta = cos(_theta * M_PI / 180);
      _sin_theta = sin(_theta * M_PI / 180);

      y_rotation_matrix[0][0] = _cos_phi;
      y_rotation_matrix[0][2] = -_sin_phi;
      y_rotation_matrix[2][1] = _sin_phi;
      y_rotation_matrix[2][2] = _cos_phi;

      x_rotation_matrix[1][1] = _cos_theta;
      x_rotation_matrix[1][2] = _sin_theta;
      x_rotation_matrix[2][1] = _cos_theta;
      x_rotation_matrix[2][2] = -_sin_theta;
      
      axonometric_projection_matrix = matrix_multiply(y_rotation_matrix, x_rotation_matrix);
      break;

    case 3:
      std::cout << "\nEnter the angle (phi) along y-axis: ";
      std::cin >> _theta;
      std::cout << "\nEnter the angle (theta) along x-axis: ";
      std::cin >> _phi;
      
      _cos_phi = cos(_phi * M_PI / 180);
      _sin_phi = sin(_phi * M_PI / 180);
      
      _cos_theta = cos(_theta * M_PI / 180);
      _sin_theta = sin(_theta * M_PI / 180);

      x_rotation_matrix[1][1] = _cos_theta;
      x_rotation_matrix[1][2] = _sin_theta;
      x_rotation_matrix[2][1] = _cos_theta;
      x_rotation_matrix[2][2] = -_sin_theta;

      y_rotation_matrix[0][0] = _cos_phi;
      y_rotation_matrix[0][2] = -_sin_phi;
      y_rotation_matrix[2][1] = _sin_phi;
      y_rotation_matrix[2][2] = _cos_phi;
      
      axonometric_projection_matrix = matrix_multiply(y_rotation_matrix, x_rotation_matrix);
      break;

    case 0:
      exit(0);

    default:
      std::cout << "\nInvalid Choice!!! Try again!!!";
      exit(0);
      break;
  }
  
  axonometric_projection_matrix = matrix_multiply(axonometric_projection_matrix, z_ortho_matrix);
  projected_figure = matrix_multiply(_transformed_figure, axonometric_projection_matrix);

  return projected_figure;
}

std::vector<std::vector<double> > projection::perspective_projection(std::vector<std::vector<double> > &_transformed_figure) {
  int perspective_projection_choice;
  double p = 0, q = 0, r = 0;
  double x = 0, y = 0, z = 0;

  std::vector<std::vector<double> > projected_figure;
  std::vector<std::vector<double> > perspective_projection_matrix { {1, 0, 0, p},
                                                                    {0, 1, 0, q},
                                                                    {0, 0, 1, r},
                                                                    {0, 0, 0, 1} };

  std::vector<std::vector<double> > z_ortho_matrix = { {1, 0, 0, 0},
                                                       {0, 1, 0, 0},
                                                       {0, 0, 0, 0},
                                                       {0, 0, 0, 1} };

  std::cout << "\n----- Perspective Projection Menu -----"
            << "\n1. 1-Point Perspective Projection"
            << "\n2. 2-Point Perspective Projection"
            << "\n3. 3-Point Perspective Projection"
            << "\n0. Exit"
            << "\n\nEnter the choice : ";
  std::cin >> perspective_projection_choice;

  switch (perspective_projection_choice) {
    case 1:
      std::cout << "\nEnter the Centre Of Projection (COP) (x) : ";
      std::cin >> x;
      if (x != 0)
        p = -1 / x;
      if (x == 0) {
        std::cout << "\nEnter the Centre Of Projection (COP) (y) : ";
        std::cin >> y;
        if (y != 0)
          q = -1 / y;
      }
      if (y == 0 && x == 0) {
        std::cout << "\nEnter the Centre Of Projection (COP) (z) : ";
        std::cin >> z;
        if (z != 0)
          r = -1 / z;
      }
      break;
    
    case 2:
      std::cout << "\nEnter the Centre Of Projection (COP) (x, y) : ";
      std::cin >> x >> y;
      if (x != 0 && y != 0) {
        p = -1 / x;
        q = -1 / y;
      }
      if (x == 0 && y == 0) {
        std::cout << "\nEnter the Centre Of Projection (COP) (y, z) : ";
        std::cin >> y >> z;
        if (y != 0 && z != 0) {
          q = -1 / y;
          r = -1 / z;
        }
      }
      if (y == 0 && z == 0) {
        std::cout << "\nEnter the Centre Of Projection (COP) (z, x) : ";
        std::cin >> z >> x;
        if (z != 0 && x != 0) {
          r = -1 / z;
          p = -1 / x;
        }
      }
      break;
    
    case 3:
      std::cout << "\nEnter the Centre Of Projection (COP) (x, y, z) : ";
      std::cin >> x >> y >> z;
      if (x != 0 && y != 0 && z != 00) {
        p = -1 / x;
        q = -1 / y;
        r = -1 / z;
      }
      break;
    
    case 0:
      exit(0);

    default:
      std::cout << "\nInvalid Choice!!! Try again!!!";
      exit(0);
      break;
  }

  perspective_projection_matrix[0][3] = p;
  perspective_projection_matrix[1][3] = q;
  perspective_projection_matrix[2][3] = r;
  perspective_projection_matrix = matrix_multiply(perspective_projection_matrix, z_ortho_matrix);
  projected_figure = matrix_multiply(_transformed_figure, perspective_projection_matrix);

  return projected_figure;
}

