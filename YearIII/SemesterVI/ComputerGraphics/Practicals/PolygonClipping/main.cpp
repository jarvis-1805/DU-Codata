/**
 * @file main.cpp
 * @author Shubhang Gupta (https://github.com/jarvis-1805)
 * @brief Write a program to clip a polygon using Sutherland Hodgeman algorithm.
 * @version 0.1
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <stdio.h>
#include <graphics.h>

using namespace std;

const int MAX_POINTS = 20;

// Returns x-value of point of intersection of two lines
int x_intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	int num = (x1*y2 - y1*x2) * (x3-x4) - (x1-x2) * (x3*y4 - y3*x4);
	int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
	return num/den;
}

// Returns y-value of point of intersection of two lines
int y_intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	int num = (x1*y2 - y1*x2) * (y3-y4) - (y1-y2) * (x3*y4 - y3*x4);
	int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
	return num/den;
}

void draw_polygon(int size, int points[][2]) {
	int i;
	for (i = 0; i < size - 1; i+=1) {
    line(points[i][0], points[i][1], points[i+1][0], points[i+1][1]);
  }
	line(points[i][0], points[i][1], points[0][0], points[0][1]);
}

// Clipping all the edges w.r.t one clip edge of clipping area
void clip(int poly_points[][2], int &poly_size, int x1, int y1, int x2, int y2) {
	int new_points[MAX_POINTS][2], new_poly_size = 0;

	// (ix,iy),(kx,ky) are the co-ordinate values of the points
	for (int i = 0; i < poly_size; i++) {
		// i and k form a line in polygon
		int k = (i+1) % poly_size;
		int ix = poly_points[i][0], iy = poly_points[i][1];
		int kx = poly_points[k][0], ky = poly_points[k][1];

		// Calculating position of first point w.r.t. clipper line
		int i_pos = (x2-x1) * (iy-y1) - (y2-y1) * (ix-x1);

		// Calculating position of second point w.r.t. clipper line
		int k_pos = (x2-x1) * (ky-y1) - (y2-y1) * (kx-x1);

		// Case 1 : When both points are inside
		if (i_pos < 0 && k_pos < 0) {
			//Only second point is added
			new_points[new_poly_size][0] = kx;
			new_points[new_poly_size][1] = ky;
			new_poly_size++;
		}

		// Case 2: When only first point is outside
		else if (i_pos >= 0 && k_pos < 0) {
			// Point of intersection with edge and the second point is added
			new_points[new_poly_size][0] = x_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
			new_points[new_poly_size][1] = y_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
			new_poly_size++;

			new_points[new_poly_size][0] = kx;
			new_points[new_poly_size][1] = ky;
			new_poly_size++;
		}

		// Case 3: When only second point is outside
		else if (i_pos < 0 && k_pos >= 0) {
			//Only point of intersection with edge is added
			new_points[new_poly_size][0] = x_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
			new_points[new_poly_size][1] = y_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
			new_poly_size++;
		}

		// Case 4: When both points are outside
		else {
			//No points are added
		}
	}

	// Copying new points into original array and changing the no. of vertices
	poly_size = new_poly_size;
	for (int i = 0; i < poly_size; i++) {
		poly_points[i][0] = new_points[i][0];
		poly_points[i][1] = new_points[i][1];
	}
}

// Implements Sutherland–Hodgman algorithm
void suthHodgClip(int poly_points[][2], int poly_size, int clipper_points[][2], int clipper_size) {
	int i, k;
	for (i=0; i<clipper_size; i++) {
		k = (i+1) % clipper_size;

		// Passing the current array of vertices, it's size and
    // the end points of the selected clipper line
		clip(poly_points, poly_size, clipper_points[i][0],
			    clipper_points[i][1], clipper_points[k][0],
			    clipper_points[k][1]);
	}

	// Printing vertices of clipped polygon
	cout << "\nVertices of the clipped polygon are :";
	for (i=0; i < poly_size; i++) {
		cout << "\n(x" << i << ", y" << i << ") : ("
					<< poly_points[i][0] << ", " << poly_points[i][1] << ") ";
	}
	draw_polygon(poly_size, poly_points);
}

int main() {
	cout << "\n============ SUTHERLAND HODGEMAN ALGORITHM ============\n";
	int i;
  int x0, y0, x1, y1;

	int poly_size;
	cout << "\nEnter the size of polygon : ";
	cin >> poly_size;
	int poly_points[MAX_POINTS][2];

	int clipper_size;
	cout << "\nEnter the size of clipper : ";
	cin >> clipper_size;
	int clipper_points[MAX_POINTS][2];

	cout << "\nEnter the points of polygon : \n";
	for (i = 0; i < poly_size; i++) {
		cout << "Enter the point " << i+1 << " : ";
		cin >> poly_points[i][0] >> poly_points[i][1];
	}
	
	cout << "\nEnter the points of clipper : \n";
	for (i = 0; i < clipper_size; i++) {
		cout << "Enter the point " << i+1 << " : ";
		cin >> clipper_points[i][0] >> clipper_points[i][1];
	}

  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  setbkcolor(RED);

	draw_polygon(poly_size, poly_points);
	draw_polygon(clipper_size, clipper_points);

  delay(3000);
  cleardevice();
  delay(200);

	draw_polygon(clipper_size, clipper_points);

	suthHodgClip(poly_points, poly_size, clipper_points, clipper_size);

	getch();
	return 0;
}

