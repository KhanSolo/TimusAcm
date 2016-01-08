/*
1. R = R - r;  Then You will solve problem with N points and a circle of radius R
2. Build 2 circles thru all pairs of points (it is n*(n-1) circles) 
and calculate amount of points in this circles. Maximum of them is the answer.


–ассматриваем 3 города(r) и окружность(R), котора€ их охватывает на пределе
“огда их центры лежат на окружности радиуса R-r

“еперь строим эту окружность проход€щую через каждую пару точек (в одну и другую стороны)
» смотрим, сколько точек в неЄ уложилось

“.о. перебором находим макс кол-во охваченных точек


 ол-во пар точек		 : n*(n-1)/2
 ол-во окружностей (R-r) : n*(n-1)

примерное число действий дл€ макс. грничных условий: 1000000
т.о. должны уложитьс€ в 1 с

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	// центры городов
	vector<pair<int, int>> points(n);

	for (int i = 0; i < n;i++)
	{
		int x, y;
		cin >> x >> y;
		points[i] = make_pair(x, y);
	}

	int r, R;

	cin >> R >> r;

	R -= r;

	//---
	// TODO
	//---

	return 0;
}