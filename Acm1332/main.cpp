/*
���������� 3 ������(r) � ����������(R), ������� �� ���������� �� �������
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
	int n;	cin >> n;

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
	int max = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i!=j)
			{
				// ���������� �� 2� ������


			}
		}
	//---

	cout << max << endl;

	return 0;
}