#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
	int m, n, min=32, temp;
	char input;
	bool flag;
	cin >> m >> n;
	bool** arr = new bool* [m];
	for (int i = 0; i < m; i++) {
		arr[i] = new bool[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			if (input == 'W') {
				arr[i][j] = true;
			}
			else {
				arr[i][j] = false;
			}
		}
	}
	for (int i = 0; i <= m - 8; i++) {
		for (int j = 0; j <= n- 8; j++) {
			//하양부터 칠하기
			temp = 0;
			flag = true;
			for (int k = i; k < i + 8; k++) {
				for (int l = j; l < j + 8; l++) {
					if (flag != arr[k][l]) {
						temp++;
					}
					flag = !flag;
				}
				flag = !flag;
			}
			if (temp < min) {
				min = temp;
			}
			//검정부터 칠하기
			temp = 0;
			flag = false;
			for (int k = i; k < i + 8; k++) {
				for (int l = j; l < j + 8; l++) {
					if (flag != arr[k][l]) {
						temp++;
					}
					flag = !flag;
				}
				flag = !flag;
			}
			if (temp < min) {
				min = temp;
			}
		}
	}
	cout << min << '\n';
	for (int i = 0; i < m; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}

