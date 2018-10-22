/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Ikbal Ramadanov Rasimov
* @idnumber 62168
* @task 7
* @compiler VC
*
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <numeric>

using namespace std;

/** IMPORTANT: Input the triangles' vertices with at least
4 digits after the decimal point to ensure correct output. */

/** Example test case: 0 0 2 0 1 1.7320508075 1 0 3 0 2 1.7320508075 */

/**
* 
* Used for comparison of floating-point numbers.
*/
const double EPSILON = 0.005;

double getHypotenuse(double a, double b);
bool areFloatsEqual(double a, double b);
double getSideLength(double ax, double ay, double bx, double by);
bool areSidesEqual(double ax, double ay, double bx, double by, double cx, double cy);
bool isTriangleUpright(double ay, double by, double cy);
double dotProduct(double ax, double ay, double bx, double by);
double getMin(double a, double b, double c);
double getMax(double a, double b, double c);
double getOverlapOnAxis(double ax1, double ay1, double bx1, double by1, double cx1, double cy1,
	double ax2, double ay2, double bx2, double by2, double cx2, double cy2,
	double axisx, double axisy);
double getOverlapArea(double ax1, double ay1, double bx1, double by1, double cx1, double cy1,
	double ax2, double ay2, double bx2, double by2, double cx2, double cy2);

int main()
{
	double ax1, ay1, bx1, by1, cx1, cy1, ax2, ay2, bx2, by2, cx2, cy2;
	cout << "Enter the triangle vertices in the format ax1-ay1-bx1-by1-cx1-cy1-ax2-ay2-bx2-by2-cx2-cy2" << endl;
	cin >> ax1 >> ay1 >> bx1 >> by1 >> cx1 >> cy1 >> ax2 >> ay2 >> bx2 >> by2 >> cx2 >> cy2;

	bool isTriangleUpright1 = isTriangleUpright(ay1, by1, cy1);
	bool isTriangleUpright2 = isTriangleUpright(ay2, by2, cy2);
	bool areSidesEqual1 = areSidesEqual(ax1, ay1, bx1, by1, cx1, cy1);
	bool areSidesEqual2 = areSidesEqual(ax2, ay2, bx2, by2, cx2, cy2);

	if (!areSidesEqual1)
	{
		cout << "Points 0, 1 and 2 do not form an equilateral triangle." << endl;
	}
	if (!areSidesEqual2)
	{
		cout << "Points 3, 4 and 5 do not form an equilateral triangle." << endl;
	}
	if (!isTriangleUpright1)
	{
		cout << "Points 0, 1 and 2 do not form an upright triangle." << endl;
	}
	if (!isTriangleUpright2)
	{
		cout << "Points 3, 4 and 5 do not form an upright triangle." << endl;
	}

	if (isTriangleUpright1 && isTriangleUpright2 && areSidesEqual1 && areSidesEqual2)
	{
		cout << "The overlap area of the two triangles is equal to "
			<< getOverlapArea(ax1, ay1, bx1, by1, cx1, cy1, ax2, ay2, bx2, by2, cx2, cy2) << endl;
	}

	return 0;
}

/**
* Gets the hypotenuse of a triangle.
* @param a length of first leg (cathetus)
* @param b length of second leg (cathetus)
* @return the length of the hypotenuse
*/
double getHypotenuse(double a, double b)
{
	return sqrt(a * a + b * b);
}

/**
* Checks if two floating-point numbers are equal.
* @param a first number
* @param b second number
* @return true if equal, false otherwise
*/
bool areFloatsEqual(double a, double b)
{
	return fabs(a - b) < EPSILON;
}

/**
* Gets the length of a side of a given triangle.
* @param ax x coordinate of first point
* @param ay y coordinate of first point
* @param bx x coordinate of second point
* @param by y coordinate of second point
* @return the length of the side
*/
double getSideLength(double ax, double ay, double bx, double by)
{
	double abx = fabs(ax - bx);
	double aby = fabs(ay - by);

	return getHypotenuse(abx, aby);
}

/**
* Checks if a triangle is equilateral.
* @param ax x coordinate of first point
* @param ay y coordinate of first point
* @param bx x coordinate of second point
* @param by y coordinate of second point
* @param cx x coordinate of third point
* @param cy y coordinate of third point
* @return true if all sides are equal, false otherwise
*/
bool areSidesEqual(double ax, double ay, double bx, double by, double cx, double cy)
{
	double sideAB = getSideLength(ax, ay, bx, by);
	double sideAC = getSideLength(ax, ay, cx, cy);
	double sideBC = getSideLength(bx, by, cx, cy);

	return areFloatsEqual(sideAB, sideAC) && areFloatsEqual(sideAB, sideBC);

}

/**
* Checks if a triangle is upright.
* @param ay y coordinate of first point
* @param by y coordinate of second point
* @param cy y coordinate of third point
* @return
*/
bool isTriangleUpright(double ay, double by, double cy)
{
	// TODO: check if this is the correct way of float comparison (the ">" sign).
	bool uprightA = areFloatsEqual(by, cy) && ay > by;
	bool uprightB = areFloatsEqual(ay, cy) && by > ay;
	bool uprightC = areFloatsEqual(ay, by) && cy > ay;

	return uprightA || uprightB || uprightC;
}

/**
* Calculates the dot product of two vectors
* @param ax x coordinate of first vector
* @param ay y coordinate of first vector
* @param bx x coordinate of second vector
* @param by y coordinate of second vector
* @return the dot product of the vectors.
*/
double dotProduct(double ax, double ay, double bx, double by)
{
	return ax * bx + ay * by;
}

/**
* Gets the minimum of three numbers.
* @param a first number
* @param b second number
* @param c third number
* @return the minimum number
*/
double getMin(double a, double b, double c)
{
	double minAB = (a < b) ? a : b;
	return ((minAB < c) ? minAB : c);
}

/**
* Gets the maximum of three numbers.
* @param a first number
* @param b second number
* @param c third number
* @return the maximum number
*/
double getMax(double a, double b, double c)
{
	double maxAB = (a > b) ? a : b;
	return ((maxAB > c) ? maxAB : c);
}

/**
* Calculates the signed length of the overlap between
* two triangles over an axis.
* @param ax1 x coordinate of first point in the first triangle
* @param ay1 y coordinate of first point in the first triangle
* @param bx1 x coordinate of second point in the first triangle
* @param by1 y coordinate of second point in the first triangle
* @param cx1 x coordinate of third point in the first triangle
* @param cy1 y coordinate of third point in the first triangle
* @param ax2 x coordinate of first point in the second triangle
* @param ay2 y coordinate of first point in the second triangle
* @param bx2 x coordinate of second point in the second triangle
* @param by2 y coordinate of second point in the second triangle
* @param cx2 x coordinate of third point in the second triangle
* @param cy2 y coordinate of third point in the second triangle
* @param axisx x coordinate of the axis
* @param axisy y coordinate of the axis
* @return the length of the overlap between two triangles.
* Overlap is bigger than zero if triangles are separate,
* and smaller than zero if triangles are intersecting.
*/
double getOverlapOnAxis(double ax1, double ay1, double bx1, double by1, double cx1, double cy1,
	double ax2, double ay2, double bx2, double by2, double cx2, double cy2,
	double axisx, double axisy)
{
	double dotA1 = dotProduct(ax1, ay1, axisx, axisy);
	double dotB1 = dotProduct(bx1, by1, axisx, axisy);
	double dotC1 = dotProduct(cx1, cy1, axisx, axisy);
	double dotA2 = dotProduct(ax2, ay2, axisx, axisy);
	double dotB2 = dotProduct(bx2, by2, axisx, axisy);
	double dotC2 = dotProduct(cx2, cy2, axisx, axisy);

	double min1 = getMin(dotA1, dotB1, dotC1);
	double min2 = getMin(dotA2, dotB2, dotC2);
	double max1 = getMax(dotA1, dotB1, dotC1);
	double max2 = getMax(dotA2, dotB2, dotC2);

	double proj1 = max1 - min1;
	double proj2 = max2 - min2;

	// Get the signed distance between the shadows that the triangles cast on the axis.
	double distanceProj = (max1 > max2 ? max1 : max2) - (min1 < min2 ? min1 : min2);
	return (distanceProj - (proj1 + proj2));

}

/**
* Gets the area of overlap between two equilateral and upright triangles.
*
* @param ax1 x coordinate of first point in the first triangle
* @param ay1 y coordinate of first point in the first triangle
* @param bx1 x coordinate of second point in the first triangle
* @param by1 y coordinate of second point in the first triangle
* @param cx1 x coordinate of third point in the first triangle
* @param cy1 y coordinate of third point in the first triangle
* @param ax2 x coordinate of first point in the second triangle
* @param ay2 y coordinate of first point in the second triangle
* @param bx2 x coordinate of second point in the second triangle
* @param by2 y coordinate of second point in the second triangle
* @param cx2 x coordinate of third point in the second triangle
* @param cy2 y coordinate of third point in the second triangle
* @return the area of overlap between triangles.
*/
double getOverlapArea(double ax1, double ay1, double bx1, double by1, double cx1, double cy1,
	double ax2, double ay2, double bx2, double by2, double cx2, double cy2)
{
	double overlap1 = getOverlapOnAxis(ax1, ay1, bx1, by1, cx1, cy1, ax2, ay2, bx2, by2, cx2, cy2, 0, 1);
	double overlap2 = getOverlapOnAxis(ax1, ay1, bx1, by1, cx1, cy1, ax2, ay2, bx2, by2, cx2, cy2, sqrt(0.75),
		-0.5);
	double overlap3 = getOverlapOnAxis(ax1, ay1, bx1, by1, cx1, cy1, ax2, ay2, bx2, by2, cx2, cy2, sqrt(0.75), 0.5);

	if (overlap1 >= 0 || overlap2 >= 0 || overlap3 >= 0) { return 0; }
	double minOverlap = getMax(overlap1, overlap2, overlap3); // Minimum overlap is actually the biggest number.

	return minOverlap * minOverlap / sqrt(3);
}