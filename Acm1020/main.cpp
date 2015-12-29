#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

double pow2(double a) { return a*a; }

int main()
{		
	const double PI = 3.14159265359;

	int n;
	double r;
	cin >> n >> r;

	vector<double> x(n), y(n);

	for (int i = 0; i < n; i++)	
		cin >> x[i] >> y[i];

	double s = 2 * PI*r;
	
	if (n>1)  
	{
		for (int i=1; i < n; i++) 
			s+=sqrt(pow2(x[i]-x[i-1])+pow2(y[i]-y[i-1]));

		s+=sqrt(pow2(x[n-1]-x[0])+pow2(y[n-1]-y[0]));
	}
	
	cout << fixed << setprecision(2);
	cout << s << endl;

	return 0;
}