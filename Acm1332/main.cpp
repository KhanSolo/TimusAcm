/*
1. R = R - r;  Then You will solve problem with N points and a circle of radius R
2. Build 2 circles thru all pairs of points (it is n*(n-1) circles) 
and calculate amount of points in this circles. Maximum of them is the answer.


������������� 3 ������(r) � ����������(R), ������� �� ���������� �� �������
����� �� ������ ����� �� ���������� ������� R-r

������ ������ ��� ���������� ���������� ����� ������ ���� ����� (� ���� � ������ �������)
� �������, ������� ����� � �� ���������

�.�. ��������� ������� ���� ���-�� ���������� �����


���-�� ��� �����		 : n*(n-1)/2
���-�� ����������� (R-r) : n*(n-1)

��������� ����� �������� ��� ����. �������� �������: 1000000
�.�. ������ ��������� � 1 �

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	// ������ �������
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