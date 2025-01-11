#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main(void) {
	int m, n, maxsquare, max=1;
	string line;
	char enter;
	bool flag=false;
	cin >> m >> n;
	char** arr = new char* [m];
	for (int i = 0; i < m; i++) {
		arr[i] = new char[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	maxsquare = min(m, n);
	for (int k = maxsquare; k > 1&&!flag; k--) {
		for (int i = 0; i <= m - k&&!flag; i++) {
			for (int j = 0; j <= n - k; j++) {
				if (arr[i][j] == arr[i + k - 1][j]&& arr[i][j]==arr[i][j + k - 1]&& arr[i][j]==arr[i + k - 1][j + k - 1]) {
					max = k;
					flag = true;
					break;
				}
			}
		}
	}
	cout << pow(max, 2) << '\n';
	for (int i = 0; i < m; i++) {
		delete[]arr[i];
	}
	delete[] arr;
	return 0;
}
