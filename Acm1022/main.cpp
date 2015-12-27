#include <iostream>
#include <vector>

using namespace std;

enum TYPE_VERTEX
{
	WHITE, GRAY, BLACK
};


// поиск в глубину
void dfs
	(
		int cur, 
		vector<int> &ans, 
		vector<TYPE_VERTEX> &v_color, 
		vector<vector<int>> &adj
	)
{
	v_color[cur] = GRAY;
	for (int i = 0; i<adj[cur].size(); i++) 
	{
		int next = adj[cur][i];
		
		if (v_color[next] == WHITE)
			dfs(next, ans, v_color, adj);
	}
	v_color[cur] = BLACK;
	ans.push_back(cur);
}


// топологическ€ сортировка

// «апускаем серию поисков в глубину, 
// чтобы обойти все вершины графа. 
// ќтсортируем вершины по времени выхода по убыванию - это и будет ответом.

void topological_sort
	(
		vector<int> &ans, 
		vector<TYPE_VERTEX> &v_color, 
		vector<vector<int>> &adj
	)
{
	int sz = v_color.size();
	for (int i = 0; i < sz; i++) 
	{
		if (v_color[i] == WHITE) 
		{
			dfs(i, ans, v_color, adj);
		}
	}
}

// заюзаем топологическую сортировку
int main()
{
	int n; // к-во членов совета
	cin >> n;
	
	vector<int> vec_init(n);
	vector<vector<int>> adj(n, vec_init); // граф
	vector<TYPE_VERTEX> v_color;



	return 0;
}