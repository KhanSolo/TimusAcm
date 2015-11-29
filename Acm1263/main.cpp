#include <iostream>
#include <iomanip> // format
#include <vector>
using namespace std;

void main()
{
	int izb = 0, 
		cand = 0;

	cin >> cand>> izb ;

	vector<int> v(cand);

	for (int i = 0; i < izb; i++)
	{
		int cell;
		cin >> cell;
		cell--;
		v[cell]++;
	}

	cout << fixed << setprecision(2);
	for (int i = 0; i < cand; i++) 
	{
		float a = static_cast<float>(v[i] * 100) 
			/ 
			static_cast<float>(izb);
	
		cout << a << "%" << endl;
	}
}