/*
Не нужно считать углы и отрезки
просто считаем суммарную длину проекции на w и d
Т.к. движение равномерное - просто находим гипотенузу
(сумма проекций на стороны комнаты -  это катеты)
*/

/*
test
4 6
2 1
2 5
R
---
5.6569
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	int w, d; 			cin >> w >> d;
	double x0, y0; 		cin >> x0 >> y0;
	double x1, y1; 		cin >> x1 >> y1;
	string directions; 	cin >> directions;

	double x = 0, y = 0; // суммарные длины проекций


	char prev_x = 0;
	char prev_y = 0;
	for (auto iter = directions.begin(); iter != directions.end(); ++iter)
	{
		char ch = *iter;
		switch(ch)
		{
		//--- Y
		case 'F':
			if (0 == prev_y)	y += y0;			
			else 
				if('B' == prev_y)	y += d;
			
			prev_y = 'F';
			break;


		case 'B':
			if (0 == prev_y)	y += (d - y0);			
			else 
				if('F' == prev_y)	y += d;			

			prev_y = 'B';
			break;
		//---

		//--- X
		case 'L':

			if (0 == prev_x)			
				x += x0;
			
			else 
				if ('R' == prev_x)			
				x += w;
			
			prev_x = 'L';
			break;

		case 'R':

			if (0 == prev_x)			
				x += (w - x0);			
			else 
				if ('L' == prev_x)			
				x += w;
			
			prev_x = 'R';
			break;
		//---
		}
	}
	// отрезок от стенки до конечной точки
	if ('B' == prev_y)
		y += d - y1;
	else
		if ('F' == prev_y)
			y += y1;
		else
			if (0 == prev_y)
				y += abs(y0 - y1);
		
	if ('R' == prev_x)
		x += w - x1;
	else
		if ('L' == prev_x)
			x += x1;
		else
			if (0 == prev_x)
				x += abs(x0 - x1);
	//---
	
		// гипотенуза
	double length = sqrt(x*x+y*y);
	
	cout << fixed << setprecision(4);
	cout << length << endl;

	return 0;
}