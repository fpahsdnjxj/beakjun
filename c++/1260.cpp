#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;

void dfs(bool** arr, int v, int n, bool*visited) {
	int node;
	vector <int> stack;
	vector <int> nodes;
	stack.push_back(v);
	while (!stack.empty()) {
		node = stack.back();
		stack.pop_back();
		if (!visited[node-1]) {
			nodes.push_back(node);
			visited[node - 1] = true;
			for (int i = n; i>=1; i--) {
				if (arr[node-1][i-1]&&!visited[i-1]) {
					stack.push_back(i);
				}
			}
		}
	}
	for (int i = 0; i < nodes.size() - 1; i++) {
		cout << nodes[i] << ' ';
	}
	cout << nodes.back()<<'\n';//DFS
}

void bfs(bool** arr, int v, int n, bool*visited) {
	int node;
	vector<int> nodes;
	queue<int>q;
	q.push(v);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (!visited[node-1]) {
			nodes.push_back(node);
			visited[node - 1] = true;
			for (int i = 1; i <= n; i++) {
				if (arr[node-1][i-1]) {
					q.push(i);
				}
			}
		}
	}
	for (int i = 0; i < nodes.size() - 1; i++) {
		cout << nodes[i] << ' ';
	}
	cout << nodes.back();
}

int main(void) {
	int m, n, v, n1, n2, node;
	cin >> n >> m >> v;
	vector <int> stack;
	vector <int> nodes;
	bool** arr = new bool* [n];
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) {
		arr[i] =new bool[n];
		visited[i] = false;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = false;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		arr[n1-1][n2-1] = true;
		arr[n2-1][n1-1] = true;
	}//간선 입력 받기


	dfs(arr, v, n, visited);
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	bfs(arr, v, n, visited);

	delete[]visited;
	for (int i = 0; i < n; i++) {
		delete[]arr[i];
	}
	delete[] arr;
	return 0;
}

