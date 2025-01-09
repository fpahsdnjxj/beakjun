#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
	int n1, n2, sum=0, temp,temp2, add, start;
	double pro, result;
	cin >> n1>>n2;
	if (n1 == n2) {
		sum = 10 - n1;
	}
	else {
		sum = 8;
		add = n1 + n2;
		if (add >= 10) {
			add -= 10;
		}
		for (int i =9; i >= add; i--) {
			for (int j = 1; j < (i+1)/2; j++) {
				temp2 = i - j;
				if ((j == n1 && temp2 == n2) || (j == n2 && temp2 == n1)) {
					sum += 1;
				}
				else if (j == n1 || j == n2 || temp2 == n1 || temp2 == n2) {
					sum += 2;
				}
				else {
					sum += 4;
				}
			}//더해서 한자리수 나오는거 구하기

			temp = i + 10;
			if (i > 0) {
				start = i;
			}
			else {
				start = 1;
			}
			for (int j = start; j < (temp+1)/2; j++) {
				temp2 = temp- j;
				if ((j == n1 && temp2 == n2) || (j == n2 && temp2 == n1)) {
					sum += 1;
				}
				else if (j == n1 || j == n2 || temp2 == n1 || temp2 == n2) {
					sum += 2;
				}
				else {
					sum += 4;
				}
			}//더해서 두자리수 나오는거 구하기
		}
	}
	pro = ((153 - sum)*1000 / (double)153);
	temp=round(pro);
	if (temp <1000) {
		cout << "0.";
		cout << temp / 100;
		temp = temp % 100;
		cout << temp / 10;
		cout << temp % 10<<'\\n';
	}
	else {
		cout << "1.000"<<'\\n';
	}

	return 0;
}


