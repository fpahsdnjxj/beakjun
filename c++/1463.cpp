#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void) {
	int n, result=0;
	int* gp = new int[1000001];
	cin >> n;
	gp[1] = 0;
	for (int i = 2; i <= n; i++) {
		gp[i] = gp[i - 1] +1;
		if (i % 2 == 0) {
			gp[i] = min(gp[i], gp[i / 2]+1);
		}
		if (i % 3 == 0) {
			gp[i] = min(gp[i], gp[i / 3]+1);
		}
	}
	cout << gp[n];
	delete[] gp;
	return 0;
}
