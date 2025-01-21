#include <iostream>
#include <vector>
using namespace std;


bool dfs(int* max, int n, bool* visited, bool** edges) {
	int start=-1, node;
	vector<int> stack;
	vector <int> nodes;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			start = i;
		}
	}
	if (start == -1) {
		return false;
	}
	stack.push_back(start);
	while (!stack.empty()) {
		node = stack.back();
		stack.pop_back();
		visited[node] = true;
		nodes.push_back(node);
		for (int i = 0; i < n; i++) {
			if (edges[node][i] && !visited[i]) {
				stack.push_back(i);
			}
		}
	}
	*max=*max+1;
	return true;
}

int main(void) {
	int m, n, max=0, n1, n2;
	bool flag=true;
	cin >> n>> m;
	bool* visited = new bool[n];
	bool** edges = new bool* [n];
	for (int i = 0; i < n; i++) {
		edges[i] = new bool[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			edges[i][j] = false;
		}
		visited[i] = false;
	}
	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		edges[n1-1][n2-1] = true;
		edges[n2-1][n1-1] = true;
	}
	while (flag) {
		flag = dfs(&max, n, visited, edges);
	}
	cout << max;
	for (int i = 0; i < n; i++) {
		delete[] edges[i];
	}
	delete[] edges;
	delete[] visited;
	return 0;
}

