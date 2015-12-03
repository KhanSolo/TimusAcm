#include <iostream>
#include <vector>

using namespace std;

/*

Алгоритм состоит из следующих шагов.
1. Выписываются все натуральные числа из диапазона от 1 до n.

2. Перебираются все возможные пары чисел x, y, где x<=sqrt(n) и y<=sqrt(n). 
	Т.е. (1,1), (1,2),…, (1,sqrt(n)), (2,1), (2,2),…, (sqrt(n),sqrt(n)).

3. Для каждой пары чисел вычисляются значения следующих трех уравнений:

a) 4*x^2+y^2;
b) 3*x^2+y^2;
c) 3*x^2-y^2, значение вычисляется только при x>y.

4. Для каждого вычисленного значения уравнений вычисляются остатки от деления на 12, причем

a) если остаток равен 1 или 5 для значения первого уравнения;
b) если остаток равен 7 для значения второго уравнения;
с) если остаток равен 11 для значения третьего уравнения.

То в исходном ряду чисел от 1 до n число помечается как простое.
Замечание: если какое-то число Z присутствует в значениях нескольких уравнений (допустим a и b), 
	и остаток от деления на 12 этого числа удовлетворяет условиям обоих групп, 
	то число помечается два раза: сначала как простое, а потом как составное.

5. На последнем этапе проверяется кратность помеченных чисел квадратам простых чисел из диапазона от 5 до sqrt(n). 
	Если число кратно квадрату, то оно помечается как составное.

*/


class Simple
{

private:	
	vector<int> cache;
	int m_limit;
	vector<bool> is_prime;


	// решето Аткина
	// квадратичные формы
	void dosieve(int limit)
	{		

		// Предположительно простые - это целые с нечетным числом
		// представлений в данных квадратных формах.

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


		// Отсеиваем квадраты простых чисел в интервале [5, sqrt(limit)].
		// (основной этап не может их отсеять)

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

	// 15000e простое число - 163841
	Simple sim(163841, 15000);
	for (int i = 0; i < n; i++)
	{
		int vi = v[i];
		int v = sim.get_num(vi);
		cout << v << endl;
	}
}