#include <iostream>

using namespace std;


int main(void) {
	int n, index, tempmax, maxp;
	int* tarr, * parr, *maxarr;
	cin >> n;
	tarr = new int[n];
	parr = new int[n];
	maxarr = new int[n];
	maxp = 0;
	for (int i = 0; i < n; i++) {
		cin >> tarr[i];
		tarr[i] += i;
		cin >> parr[i];
		maxarr[i] = 0;
	}

	index = tarr[0] - 1;
	if (index < n) {
		for (int j = n - 1; j >= index; j--) {
			maxarr[j] = parr[0];
		}
	}//1일차의 경우

	for (int i = 1; i < n; i++) {
		index = tarr[i]-1;
		if (index < n) {
			tempmax = maxarr[i-1] + parr[i];
			if (tempmax > maxarr[index]) {
				for (int j = n - 1; j >= index; j--) {
					if (tempmax >= maxarr[j]) {
						maxarr[j] = tempmax;
					}
				}
			}
		}
	}//나머지 일차의 경우
	cout << maxarr[n-1];
	delete[]maxarr;
	delete[]tarr;
	delete[]parr;
	return 0;
}

