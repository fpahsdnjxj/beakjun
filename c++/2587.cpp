#include <iostream>

using namespace std;

void find_index(int num[5][5], int* index1, int* index2) {
	int deletenum;
	cin >> deletenum;
	for (int i = 0; i < 5; i++) {
		for (int j= 0; j< 5; j++) {
			if (num[i][j] == deletenum) {
				*index1 = i;
				*index2 = j;
				return;
			}
		}
	}
	return;
}

int main(void) {
	int num[5][5];
	bool tf[5][5];
	int result, deletenum, index1, index2, linenum=0,linecheck=0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> num[i][j];
			tf[i][j] = false;
		}
	}
	for (result= 1; result <= 25; result++) {
		find_index(num, &index1, &index2);
		tf[index1][index2] = true;
		for (linecheck = 0; linecheck< 5; linecheck++) {
			if (!tf[index1][linecheck]) {
				break;
			}
		}
		if (linecheck == 5) {
			++linenum;
		}//가로줄 체크

		for (linecheck = 0; linecheck < 5; linecheck++) {
			if (!tf[linecheck][index2]) {
				break;
			}
		}
		if (linecheck == 5) {
			++linenum;
		}//세로줄 체크

		if (index1 == index2) {
			for (linecheck = 0; linecheck < 5; linecheck++) {
				if (!tf[linecheck][linecheck]) {
					break;
				}
			}
			if (linecheck == 5) {
				++linenum;
			}
		}//대각선(왼쪽 위부터) 체크

		if (index1+index2==4) {
			for (linecheck = 0; linecheck < 5; linecheck++) {
				if (!tf[linecheck][4-linecheck]) {
					break;
				}
			}
			if (linecheck == 5) {
				++linenum;
			}
		}//대각선(오른쪽 위부터)체크

		if (linenum >= 3) {
			break;
		}
	}
	cout << result;
	return 0;
}

