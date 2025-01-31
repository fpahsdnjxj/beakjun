#include <iostream>
#include <memory.h>
using namespace std;

int main(void) {
	int n, s, m;
	cin >> n >> s >> m;
	int* v = new int[n];
	bool** dp = new bool* [n+1];
	for (int i = 0; i < n + 1; i++) {
		dp[i] = new bool[m + 1];
		memset(dp[i], 0, sizeof(bool) * m + 1);
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	dp[0][s] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j<=m; j++) {
			if (dp[i - 1][j]) {
				if (j + v[i-1] <= m) {
					dp[i][j + v[i-1]] = true;
				}
				if (j - v[i-1] >= 0) {
					dp[i][j - v[i-1]] = true;
				}
			}
		}
	}
	for (int j = m; j>=0; j--) {
		if (dp[n][j]) {
			cout << j;
			delete[]v;
			for (int i = 0; i < n+1; i++) {
				delete[] dp[i];
			}
			delete[] dp;
			return 0;
		}
	}
	cout << -1;
	delete[]v;
	for (int i = 0; i < n+1; i++) {
		delete[] dp[i];
	}
	delete[] dp;
	return 0;
}

