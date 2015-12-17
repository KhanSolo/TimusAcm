#include <iostream>
#include <string>

using namespace std;

int main()
{
	string man;
	cin >> man;
	int man_size = man.size();

	const string sandro = "Sandro";
	int str_size = sandro.size();

	const int reg_cost = 5;
	const int letter_cost = 5;

	int min_cost = str_size * (reg_cost + letter_cost); 
	
	// (O(n*k))
	for (int i = 0; i < man_size - str_size + 1; ++i)
	{
		int cost = 0; // текущая стоимость
		for (int j = 0; j < str_size; ++j) 
		{
			auto m = man[i + j];
			auto s = sandro[j];

			// изменение буквы за 5 золотых
			auto lower_m = tolower(m);
			auto lower_s = tolower(s);
			
			if (lower_m != lower_s) 
				cost += letter_cost;

			// изменение регистра за 5 золотых
			auto is_m = isupper(m);
			auto is_s = isupper(s);
			if (is_m != is_s)
				cost += reg_cost;
		}
		if (cost < min_cost)		
			min_cost = cost;		
	}

	cout << min_cost;
	return 0;
}