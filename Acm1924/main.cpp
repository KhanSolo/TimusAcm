/*

�� ����� ��� �������� ����� ����� ��� 2*k+1 
�.�. �� ����� �������� �� ���������� ��� �������� ��, ��������� ���� ������ ����� => 
���� ���� ������ ����� �������� ����� �� 1 �� n �� ����� "black".

*/

#include <iostream>
using namespace std;

void main()
{
	int n;
	cin >> n;

	int odd_count = (n % 2) + (n / 2);

	cout << ((odd_count % 2 == 1) ? "grimy" : "black");
}