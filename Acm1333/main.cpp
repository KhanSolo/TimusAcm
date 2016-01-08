/*
Примерное решение (с точностью до процента)
Создаём сетку на полигоне
И проверяем каждый квадратик(центр квадратика) - внутри круга или нет
*/
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
T sqr(T a)
{
	return a*a;
}

int main()
{
	int n; cin >> n;

	vector<vector<double>> circles(n);

	for (int i = 0; i < n;i++)
	{
		double x, y, r;
		cin >> x >> y >> r;
		circles[i] = { x,y,r };
	}

	int cycles = 0;
	
	int count = 0; // число квадратов

	const double step = 0.005; //шаг сетки
	const double hs = step * 0.5; // half-step

	int dimension = 1 / step;
	vector<vector<bool>> mark(dimension, vector<bool>(dimension));

	double x, y;

	for ( x = 0.000; (1.000 - x) > 0.0; x += step)
		for ( y = 0.000; (1.000 - y) > 0.0; y += step)
		{
			cycles++;
			for (int i = 0; i < n; i++)
			{
				double xc, yc, r;
				xc = circles[i][0];
				yc = circles[i][1];
				r  = circles[i][2];

				double x0 = x + hs; // центр квадратика
				double y0 = y + hs;

				if (!mark[x/step][y/step] 
					&&
					(sqr(x0 - xc) + sqr(y0 - yc)
					 <= 
					sqr(r)
					))
				{
					mark[x / step][y / step] = true;
					count++;
				}
			}
		}

	
	double r = static_cast<double>(count) * sqr(step) * 100;
	cout << r;

	return 0;
}