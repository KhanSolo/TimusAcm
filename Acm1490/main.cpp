/*
Брезенхем
*/

#include <iostream>
using namespace std;

void drawpixel(int x, int y)
{
	cout << "(" << x << ", " << y << ")" << endl;
}

void main()
{
	int R = 1;
	int X1 = 0;
	int Y1 = 0;

	// R - радиус, X1, Y1 - координаты центра

	int x = 0;
	int y = R;
	int delta = 1 - 2 * R;
	int error = 0;
	while (y >= 0) 
	{
		drawpixel(X1 + x, Y1 + y);
		drawpixel(X1 + x, Y1 - y);
		drawpixel(X1 - x, Y1 + y);
		drawpixel(X1 - x, Y1 - y);

		cout << endl;

		error = 2 * (delta + y) - 1;
		if ((delta < 0) && (error <= 0)) 
		{
			++x;
			delta += 2 * x + 1;
			continue;
		}
		error = 2 * (delta - x) - 1;
		if ((delta > 0) && (error > 0)) 
		{
			--y;
			delta += 1 - 2 * y;
			continue;
		}
		x++;
		delta += 2 * (x - y);
		y--;
	}

}