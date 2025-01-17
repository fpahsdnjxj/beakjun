#include <iostream>
#include <vector>

using namespace std;

void get_min_max(int start, int end, int*min, int*max, int * numarr, int*operarr) {
	if (start == end) {
		int result;
		result = numarr[0];
		for (int i = 1; i <=end+1; i++) {
			if (operarr[i - 1] == 0) {
				result += numarr[i];
			}
			else if (operarr[i - 1] == 1) {
				result -= numarr[i];
			}
			else if (operarr[i - 1] == 2) {
				result *= numarr[i];
			}
			else {
				result /= numarr[i];
			}
		}
		if (*min > result) {
			*min = result;
		}
		if (*max < result) {
			*max = result;
		}
		return;
	}
	for (int i = start; i <=end ; i++) {
		swap(operarr[start], operarr[i]);
		get_min_max(start+1, end, min, max, numarr, operarr);
		swap(operarr[i], operarr[start]);
		//다른 숫자에 대해 다시 돌기
	}
}

int main(void) {
	int n, temp, index, result;
	int min = 1000000000;
	int max = -1000000000;
	cin >> n;
	int* numarr = new int[n];
	int* operarr = new int[n-1];
	for (int i = 0; i < n; i++) {
		cin >> numarr[i];
	}
	index = 0;
	for (int i = 0; i < 4; i++) {
		cin >> temp;
		for (int j = 0; j < temp; j++) {
			operarr[index] = i;
			++index;
		}
	}
	get_min_max(0, n-2, &min, &max, numarr, operarr);
	cout << max << '\n';
	cout << min << '\n';
	delete[] operarr;
	delete[] numarr;
	return 0;
}
