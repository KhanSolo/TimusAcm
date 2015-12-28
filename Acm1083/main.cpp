#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string x;
	cin >> n >> x;

	int k = x.size() ;
	int s = n;

	while(n-k>0)
	{
		n = n - k;
		s = s*n;
	}
	
	cout << s << endl;
	return 0;
}