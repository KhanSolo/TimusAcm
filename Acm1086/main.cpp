#include <iostream>
#include <vector>

using namespace std;

class Simple
{
private:	
	vector<int> cache;
	int m_limit;
	vector<bool> is_prime;

	void dosieve(int limit)
	{
		int k, n;
		
		for (int i = 0; i < limit; i++)
			is_prime[i] = false;

		int x_lim = (int)trunc(sqrt(limit));
		int y_lim = (int)trunc(sqrt(limit));

		for (int x = 1; x <= x_lim; x++)
			for (int y = 1; y <= y_lim; y++)
			{
				n = 4 * x*x + y*y;

				if ((n <= limit) &&((n % 12 == 1) || (n % 12 == 5))) 
					is_prime[n] = !is_prime[n];

				n = n - x*x;

				if ((n <= limit) &&(n % 12 == 7)) 
					is_prime[n] = !is_prime[n];

				n = n - 2 * y*y;

				if ((x>y) &&(n <= limit) && (n % 12 == 11)) 
					is_prime[n] = !is_prime[n];
			}

		int i_lim = (int)trunc(sqrt(limit));
		for (int i = 5; i <= i_lim; i++)
		{
			if (is_prime[i])
			{
				k = i*i;
				n = k;
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
	
	Simple(int limit) : 
		m_limit(limit),
		is_prime(limit+1)
	{
		// build
		dosieve(m_limit);

		cache.resize(15001); // dirty hack
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

	int get_num(int val);
};

int Simple::get_num(int val)
{
	return cache[val];
}

void main()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)	
		cin >> v[i];	

	// 15000e простое число - 163841
	Simple sim(163841);
	for (int i = 0; i < n; i++)
	{
		int vi = v[i];
		int v = sim.get_num(vi);
		cout << v << endl;
	}
}