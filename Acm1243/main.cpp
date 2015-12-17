#include <iostream>
#include <string>
using namespace std;

int main()
{
	int coef[6] = {
	1, 
	3, 
	2, 
	6, 
	4, 
	5
	};
	
	string bignum;	
	cin >> bignum;

	int r = 0;
	int n = 0;
	for (auto i = bignum.rbegin(); 
		i != bignum.rend(); 
		++i, ++n)
	{
		// *i - символ в числе
		//  (*i - '0') - цифра в числе
		r = r + 
		(*i - '0') 
		* coef[n % 6]; // todo проверить
	}

	cout << r % 7;

	return 0;
}