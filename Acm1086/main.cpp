/*

my $n=shift or die "$0: Укажите число в командной строке\n";

my @sieve=2..$n;

while(@sieve)
{
	while(@sieve and $sieve[0]==0)
	{
		shift @sieve;
	}
	last unless @sieve;
	print my $p=shift @sieve, "\n";

	for(my $i=$p-1; $i<@sieve; $i+=$p)
	{
		$sieve[$i]=0;
	}
}

*/

#include <iostream>
#include <vector>

using namespace std;

class Simple
{
private:

public:
	int process(int val);
};

int Simple::process(int val)
{
	
}

void main()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)	
		cin >> v[i];	

	Simple sim;
	for (int i = 0; i < n;i++)	
		cout << (sim.process(v[i]));	
}