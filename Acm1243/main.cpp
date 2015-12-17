#include <iostream>
#include <string>
using namespace std;

int main()
{
	int mods[6] = 
	{
		1, // 1 % 7		; 1000000 % 7
		3, // 10 % 7	; 
		2, // 100 % 7	;
		6, // 1000 % 7	;
		4, // 10000 % 7	;
		5  // 100000 % 7;
	};
	
	string bignum;	
	cin >> bignum;

	int r = 0;
	int n = 0;
	for (auto i = bignum.rbegin();  // from end to begin
		i != bignum.rend(); 
		++i, ++n)
	{
		// *i - символ в числе
		//  (*i - '0') - цифра в числе

		auto cif = (*i - '0');
			//cout << cif << " ";
		auto idx = n % 6;
			//cout << idx << " ";
		int k = mods[idx];
			//cout << k << " ";
		r = r + cif * k; // todo проверить
			//cout << r << endl;
	}

	cout << r % 7;

	return 0;
}