#include <iostream>
#include <vector>
//#include <math.h>
#include <algorithm>

using namespace std;

int main()
{	
	int n; 	
	cin >> n; // count
	vector<int> v(n, 0); // weights

	for (int i = 0; i < n; i++) 
		cin >> v[i];
	
	int t = 0;
	int r = 1 << 30;

	int iter = 1 << n;
	for (int i = 0; i < iter; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a1 = 1 << j;
			int a2 = a1 & i;

			int a3 = (a2)
				? v[j]
				: -v[j];

			t += a3;				
		}

		r = min(r, abs(t));

		//cout << r << endl;

		t = 0;
	}

	cout << r;
}

/*bool cmp( int a, int b ) {
return a > b;
}

int main()
{
int n,i;
long long int s1,s2,a[20];
cin >> n;
for (i=0; i<n; i++)
{
cin >> a[i];
}

sort(a,a+n,cmp);

s1=a[0];
s2=0;

for (i=1; i<n; i++)
{
if (abs((s1+a[i])-s2)<abs((s2+a[i])-s1)) { s1+=a[i];}
else {s2+=a[i];}
}
cout << abs(s1-s2);
}

*/