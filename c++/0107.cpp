#include <iostream>
#include <math.h>
using namespace std;
int main(void) {
	int n, m, k, j, i, sum, left, div;
	cin >> n;
	k = (static_cast<int>(log10(n)) + 1);
	j = k * 9;
	for (int m= max(0,n-j); m <n ; m++) {
		sum = m;
		left = m;
		while (left > 0) {
			sum += left % 10;
			left = left / 10;
		}
		if (sum == n) {
			cout << m;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
