#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
	int t,n, t1max, t1min, t2max, t2min, i1, n2, i2,n3, i3, t3;
	bool flag = false;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		i1 = (static_cast<int>(sqrt(8 * n + 1)) - 1) / 2;
		t1max = (i1 * (i1 + 1)) / 2;
		t1min = n / 3;
		if (t1min <= 0) {
			cout << 0 << '\\n';
			continue;
		}
		for (int t1 = t1max; t1 >= t1min&&!flag; i1--) {
			n2 = n - t1;
			if (n2 != 0) {
				i2 = (static_cast<int>(sqrt(8 * n2 + 1)) - 1) / 2;
				t2max = (i2 * (i2 + 1)) / 2;
				for (int t2 = t2max; t2 > 0; i2--) {
					n3 = n2 - t2;
					i3=(static_cast<int>(sqrt(8 * n3 + 1)) - 1) / 2;
					t3 = (i3 * (i3 + 1)) / 2;
					if (n3>0&&t3 == n3) {
						flag = true;
						break;
					}
					t2 = t2 - i2;
				}
			}
			t1 = t1 - i1;
		}
		if (flag) {
			cout << 1 << '\\n';
		}
		else {
			cout << 0<< '\\n';
		}
		flag = false;
	}
	return 0;
}



