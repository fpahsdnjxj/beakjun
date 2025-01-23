#include <iostream>
#include <queue>
#include <vector>
#include<algorithm>

using namespace std;
bool bfs(bool** point, vector <int>& num, int n, int* comnum) {
	int x=-1, y=-1, result=0;
	bool flag=false;
	queue<int> nodequeue[2];
	for (int i = 0; i < n&&!flag; i++) {
		for (int j = 0; j < n; j++) {
			if (point[i][j]) {
				x = i;
				y = j;
				flag = true;
				break;
			}
		}
	}
	if (x == -1) {
		return false;
	}
	nodequeue[0].push(x);
	nodequeue[1].push(y);
	point[x][y] = false;
	while (!nodequeue[0].empty()) {
		x = nodequeue[0].front();
		y = nodequeue[1].front();
		nodequeue[0].pop();
		nodequeue[1].pop();
		++result;

		if (x > 0 && point[x - 1][y]) {
			nodequeue[0].push(x-1);
			nodequeue[1].push(y);
			point[x-1][y] = false;
		}
		if (x < n - 1 && point[x + 1][y]) {
			nodequeue[0].push(x+1);
			nodequeue[1].push(y);
			point[x +1][y] = false;
		}
		if (y > 0 && point[x][y - 1]) {
			nodequeue[0].push(x);
			nodequeue[1].push(y-1);
			point[x][y-1] = false;
		}
		if (y < n - 1 && point[x][y + 1]) {
			nodequeue[0].push(x);
			nodequeue[1].push(y+1);
			point[x][y +1] = false;
		}
	}
	num.push_back(result);
	*comnum = *comnum + 1;
	return true;
}

int main(void) {
	int n, comnum=0;
	char input;
	bool flag=true;
	vector <int> num;
	cin >> n;
	bool** point = new bool* [n];
	for (int i = 0; i < n; i++) {
		point[i] = new bool[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			if (input == '1') {
				point[i][j] = true;
			}
			else {
				point[i][j] = false;
			}
		}
	}
	while (flag) {
		flag = bfs(point, num, n, &comnum);
	}
	cout << comnum << '\n';
	sort(num.begin(), num.end());
	for (int i = 0; i < num.size(); i++) {
		cout << num[i];
		if (i < (num.size() - 1)) {
			cout << '\n';
		}
	}
	for (int i = 0; i < n; i++) {
		delete[] point[i];
	}
	delete[]point;
	return 0;
}
