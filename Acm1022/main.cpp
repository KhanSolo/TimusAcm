#include <iostream>
#include <vector>

using namespace std;

enum TYPE_VERTEX
{
	WHITE, 
	GRAY, 
	BLACK
};

// поиск в глубину
void dfs
	(
		int cur, 
		vector<int> &ans, 
		vector<TYPE_VERTEX> &v_color, 
		vector<vector<int>> &adj // граф
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

// топологическя сортировка

// Запускаем серию поисков в глубину, 
// чтобы обойти все вершины графа. 
// Отсортируем вершины по времени выхода по убыванию - это и будет ответом.

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
	
	vector<vector<int>> adj(n, 
		vector<int>() // список дочерних вершин i-й вершины
		); // граф

	for (int i = 0; i < n; i++)
	{
		while (true)
		{
			int val;
			cin >> val;
			if (0 == val) break;

			adj[i].push_back(--val);
		}
	}
	
	// цвета вершин
	vector<TYPE_VERTEX> v_color(n,WHITE);

	vector<int> ans;
	topological_sort(ans, v_color, adj);
			
	for (auto iter = ans.rbegin(); iter != ans.rend(); ++iter)
	{
		cout << (*iter + 1) << " ";
	}

	return 0;
}