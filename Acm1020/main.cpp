/*
var x,y:array [1..100] of single;
n,i:integer;
s,r:double;
begin
readln(n,r);
for i:=1 to n do
readln(x[i],y[i]);
	s:=2*pi*r;
	if n>1 then begin
		for i:=2 to n do
		s:=s+sqrt(pow2(x[i]-x[i-1])+pow2(y[i]-y[i-1]));
			s:=s+sqrt(pow2(x[n]-x[1])+pow2(y[n]-y[1]))
	end;
writeln(s:0:2);
end.
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

double pow2(double a) { return a*a; }

int main()
{	
	
	int n;
	double s, r;
	
	const double PI = 3.14159265359;

	cin >> n >> r;

	vector<double> x(n+1), y(n+1);

	for (int i = 1; i <= n; i++)	
		cin >> x[i] >> y[i];

	s = 2 * PI*r;
	
	if (n>1)  
	{
		for (int i=2; i<= n; i++) 
			s+=sqrt(pow2(x[i]-x[i-1])+pow2(y[i]-y[i-1]));

		s+=sqrt(pow2(x[n]-x[1])+pow2(y[n]-y[1]));
	}
	
	cout << fixed << setprecision(2);
	cout << s << endl;

	return 0;
}