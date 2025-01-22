#include <iostream>
#include <vector>
using namespace std;


bool dfs(bool point[50][50], int m, int n, int *result) {
	int x = -1, y = -1;
	vector<int>stack[2];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (point[i][j]) {
				x = i;
				y = j;
				break;
			}
		}
	}
	if (x == -1) {
		return false;
	}
	stack[0].push_back(x);
	stack[1].push_back(y);
	while (!stack[0].empty()) {
		x = stack[0].back();
		y = stack[1].back();
		stack[0].pop_back();
		stack[1].pop_back();
		point[x][y] = false;

		if (x<(m-1)&&point[x + 1][y]) {
			stack[0].push_back(x+1);
			stack[1].push_back(y);
		}
		if (y<(n-1)&&point[x][y+1]) {
			stack[0].push_back(x);
			stack[1].push_back(y+1);
		}
		if (x > 0 && point[x-1][y]) {
			stack[0].push_back(x-1);
			stack[1].push_back(y);
		}
		if (y > 0 && point[x][y-1]) {
			stack[0].push_back(x);
			stack[1].push_back(y-1);
		}
	}
	*result = *result + 1;
	return true;
}

int main(void) {
	int t, m, n,k, x, y, result;
	bool flag;
	cin >> t;
	bool point[50][50];
	for (int i = 0; i < t; i++) {
		result = 0;
		flag = true;
		cin >> m >> n>>k;
		for (int a = 0; a < m; a++) {
			for (int b = 0; b < n; b++) {
				point[a][b] = false;
			}
		}
		for (int a = 0; a < k; a++) {
			cin >> x >> y;
			point[x][y] = true;
		}
		while (flag) {
			flag = dfs(point, m, n, &result);
		}
		cout << result;
		if (i < (t - 1)) {
			cout << '\n';
		}
	}
	return 0;
}

