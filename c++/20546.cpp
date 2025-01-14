#include <iostream>

using namespace std;

int main(void) {
	int k1, k2, st1=0, st2=0, p, up=0, down=0, pre;
	cin >> k1;
	k2 = k1;

	cin >> p;
	if (p <= k1) {
		st1 += k1 / p;
		k1 -= p * (k1 / p);
	}
	pre = p;//첫번째 경우 따로 처리해주기

	for (int i = 0; i < 13; i++) {
		cin >> p;
		if (pre < p) {
			down = 0;
			++up;
		}
		else if(pre>p){
			up = 0;
			++down;
		}
		else {
			up = 0;
			down = 0;
		}//상승 하락을 몇번 했는지 세보기

		if (p <=k1) {
			st1 += k1 / p;
			k1-= p * (k1 / p);
		}//BNP

		if (up >= 3&& st2 > 0) {
			k2 += p * st2;
			st2 = 0;
		}
		else if (down >= 3&&k2>=p) {
			st2 += k2 / p;
			k2 -= p * (k2 / p);
		}//TIMING

		pre = p;
	}

	k1 = k1 + p * st1;
	k2 = k2 + p * st2;//최종 자산 구하기

	if (k1 == k2) {
		cout << "SAMESAME";
	}
	else if (k1 > k2) {
		cout << "BNP";
	}
	else {
		cout << "TIMING";
	}
	return 0;
}
