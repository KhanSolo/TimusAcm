#include<iostream>
#include <vector>
using namespace std;

class MaxHeap
{
public:
	MaxHeap(int size) : m_size(size), v(size){}
	~MaxHeap(){}



private:
	int m_size;
	vector<pair<int, int>> v;
};



void main()
{
	int n;
	cin >> n;

	MaxHeap heap(n);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		pair<int, int> p(a, b);

	}
}