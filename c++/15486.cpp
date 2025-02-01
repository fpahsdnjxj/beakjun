#include <iostream>
#include<memory.h>
#include <algorithm>
using namespace std;

int main(void) {
	int n, enddate;
	cin >> n;
	int* time = new int[n];
	int* price = new int[n];
	int* maxp = new int[n];
	memset(maxp, 0, sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		cin >> time[i];
		cin >> price[i];
	}
	enddate = time[0]-1;
	if (enddate < n) {
		maxp[enddate] = price[0];
	}
	for (int i = 1; i < n; i++) {
		maxp[i] = max(maxp[i], maxp[i - 1]);
		enddate = time[i] + i-1;
		if (enddate < n) {
			maxp[enddate] = max(maxp[enddate], maxp[i-1] + price[i]);
		}
	}
	cout << maxp[n - 1];
	delete[] time;
	delete[] price;
	delete[] maxp;
	return 0;
}

