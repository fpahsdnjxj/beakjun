#include <iostream>
#include<vector>
using namespace std;
long long  fib(int end) {
	long long temp;
	vector<long long> v;
	v.push_back(0);
	v.push_back(1);
	for (int i = 2; i <= end; i++) {
		temp = v[i - 1] + v[i - 2];
		v.push_back(temp);
	}
	temp = v.back();
	return temp;
}

int main(void) {
	int n;
	long long result;
	cin >> n;
	result = fib(n);
	cout << result;
	return 0;
}
