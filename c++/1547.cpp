#include <iostream>

using namespace std;
int main(void) {
	int m, x, y, temp;
	int arr[3];
	bool flag=false;
	for (int i = 0; i < 3; i++) {
		arr[i] = i + 1;
	}//초기화 작업

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (x >= 1 && y >= 1) {
			temp = arr[x - 1];
			arr[x - 1] = arr[y - 1];
			arr[y - 1] = temp;
		}
	}//컵의 위치를 switch한다.

	for (int i = 0; i < 3; i++) {
		if (arr[i] == 1) {
			cout << i + 1 << '\n';
			flag = true;
			break;
		}
	}
	if (!flag) {
		cout << -1 << '\n';
	}
	return 0;
}
