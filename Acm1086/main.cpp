#include <iostream>
#include <vector>

using namespace std;

/*

�������� ������� �� ��������� �����.
1. ������������ ��� ����������� ����� �� ��������� �� 1 �� n.

2. ������������ ��� ��������� ���� ����� x, y, ��� x<=sqrt(n) � y<=sqrt(n). 
	�.�. (1,1), (1,2),�, (1,sqrt(n)), (2,1), (2,2),�, (sqrt(n),sqrt(n)).

3. ��� ������ ���� ����� ����������� �������� ��������� ���� ���������:

a) 4*x^2+y^2;
b) 3*x^2+y^2;
c) 3*x^2-y^2, �������� ����������� ������ ��� x>y.

4. ��� ������� ������������ �������� ��������� ����������� ������� �� ������� �� 12, ������

a) ���� ������� ����� 1 ��� 5 ��� �������� ������� ���������;
b) ���� ������� ����� 7 ��� �������� ������� ���������;
�) ���� ������� ����� 11 ��� �������� �������� ���������.

�� � �������� ���� ����� �� 1 �� n ����� ���������� ��� �������.
���������: ���� �����-�� ����� Z ������������ � ��������� ���������� ��������� (�������� a � b), 
	� ������� �� ������� �� 12 ����� ����� ������������� �������� ����� �����, 
	�� ����� ���������� ��� ����: ������� ��� �������, � ����� ��� ���������.

5. �� ��������� ����� ����������� ��������� ���������� ����� ��������� ������� ����� �� ��������� �� 5 �� sqrt(n). 
	���� ����� ������ ��������, �� ��� ���������� ��� ���������.

*/


class Simple
{

private:	
	vector<int> cache;
	int m_limit;
	vector<bool> is_prime;


	// ������ ������
	// ������������ �����
	void dosieve(int limit)
	{		

		// ���������������� ������� - ��� ����� � �������� ������
		// ������������� � ������ ���������� ������.

		int x_lim = (int)trunc(sqrt(limit));
		int y_lim = (int)trunc(sqrt(limit));

		for (int x = 1; x <= x_lim; x++)
			for (int y = 1; y <= y_lim; y++)
			{
				int n = 4 * x*x + y*y;

				if ((n <= limit)
					&& ((n % 12 == 1) || (n % 12 == 5)))
				{					
					is_prime[n] = !is_prime[n];
				}

				n = n - x*x; // 3*x*x + y*y

				if ((n <= limit)
					&& (n % 12 == 7)) 
				{
					is_prime[n] = !is_prime[n];
				}

				n = n - 2 * y*y; // 3*x*x - y*y

				if ((x > y) && (n <= limit)
					&& (n % 12 == 11))
				{
					is_prime[n] = !is_prime[n];
				}
			}


		// ��������� �������� ������� ����� � ��������� [5, sqrt(limit)].
		// (�������� ���� �� ����� �� �������)

		int i_lim = (int)trunc(sqrt(limit));
		for (int i = 5; i <= i_lim; i++)
		{
			if (is_prime[i])
			{
				int k = i*i;
				int n = k;
				while (n <= limit)
				{
					is_prime[n] = false;
					n = n + k;
				}
			}

		}
		is_prime[2] = true;
		is_prime[3] = true;
	}
	
//----------
public:
	
	Simple(int limit, int limit_num) : 
		m_limit(limit),
		is_prime(limit+1, false),
		cache(limit_num+1)
	{		
		dosieve(m_limit);
				
		int counter = 0;
		for (int i = 1; i <= limit; i++)
		{
			if (is_prime[i] == true)
			{
				counter++;
				cache[counter] = i;
			}
		}
	}

	int get_num(int num) { return cache[num]; }
};


void main()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)	
		cin >> v[i];	

	// 15000e ������� ����� - 163841
	Simple sim(163841, 15000);
	for (int i = 0; i < n; i++)
	{
		int vi = v[i];
		int v = sim.get_num(vi);
		cout << v << endl;
	}
}