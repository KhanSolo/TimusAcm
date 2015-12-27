#include <iostream>
#include <vector>

using namespace std;

enum TYPE_VERTEX
{
	WHITE, GRAY, BLACK
};


// ����� � �������
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


// ������������� ����������

// ��������� ����� ������� � �������, 
// ����� ������ ��� ������� �����. 
// ����������� ������� �� ������� ������ �� �������� - ��� � ����� �������.

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

// ������� �������������� ����������
int main()
{
	int n; // �-�� ������ ������
	cin >> n;
	
	vector<int> vec_init(n);
	vector<vector<int>> adj(n, vec_init); // ����
	vector<TYPE_VERTEX> v_color;



	return 0;
}