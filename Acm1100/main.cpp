#include<iostream>
#include <vector>
using namespace std;

typedef pair<int, int> two;

class MaxHeap
{
public:
	MaxHeap(int size) : m_size(size)/*, pq(size)*/{}
	~MaxHeap(){}

	void sort()
	{
		int n = m_size;
		for (int k = n / 2; k >= 1; k--)		
			sink(k);
		while (n > 1)
		{
			exch(1, n--);
			sink(n);
		}
	}

	void push(two t) { 	pq.push_back(t); }

	two pop(int i) 	
	{ 	
		return pq[i]; 	
	}


private:
	int m_size;
	vector<two> pq;
	
	bool less(int i, int j)
	{
		return (pq[i-1].first - pq[j-1].first) < 0;
	}
	void exch(int i, int j)
	{
		auto t = pq[i-1];
		pq[i-1] = pq[j-1];
		pq[j-1] = t;
	}
	void swim(int k)
	{
		while (k > 1 && less(k / 2, k))
		{
			exch(k / 2, k);
			k = k / 2;
		}
	}
	void sink(int k)
	{
		while (2 * k <= m_size)
		{
			int j = 2 * k;
			if (j < m_size && less(j, j + 1)) j++;
			if (!less(k, j)) break;
			exch(k, j);
			k = j;
		}
	}
};


void main()
{
	int n;
	cin >> n;
	
	// --- bubble
	
	// --- /bubble
	
	MaxHeap heap(n);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		two p(a, b);

		heap.push(p);
	}
	heap.sort();
	for (int i = 0; i < n; i++)
	{
		two p = heap.pop(i);
		cout << p.first << " " << p.second << endl;
	}
}