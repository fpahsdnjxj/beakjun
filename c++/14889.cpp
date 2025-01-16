#include <iostream>
#include<vector>

using namespace std;

void combination(int start, int depth, int n, vector<int> com, int*min, int**parr) {
	if (depth == n / 2) {//조합이 구해졌을 때
		int team1=0, team2=0, index=0, diff, index2, jindex;
		vector<int> com2;
		for (int i = 0; i < n; i++) {
			if (index < n / 2&& i == com[index]) {
				index++;
			}
			else {
				com2.push_back(i);
			}
		}//team2의 사람들 뽑아내기

		index = 0;
		index2 = 0;
		for (int i = 0; i < n ; i++) {
			if (index<n/2&&i == com[index]) {
				for (int j = index+1; j < n / 2; j++) {
					jindex = com[j];
					team1 += parr[i][jindex];
				}
				index++;
			}//team1 합 구하기
			else {
				for (int j = index2+ 1; j < n / 2; j++) {
					jindex = com2[j];
					team2 += parr[i][jindex];
				}
				index2++;
			}//team2 합 구하기
		}

		diff = abs(team2 - team1);
		if (*min > diff) {
			*min = diff;
		}//차 구하고 넘기기

		return;
	}

	for (int i = start; i < n; i++) {
		com.push_back(i);
		combination(i + 1, depth+1, n, com, min, parr);
		com.pop_back();
	}//조합 구하는 함수
}

int main(void) {
	int n, min=200000;
	cin >> n;
	int** arr=new int*[n];
	int** parr = new int* [n];
	vector<int> com;
	
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		parr[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			parr[i][j] = arr[i][j] + arr[j][i];
		}
	}//미리 조합에 따른 더해지는 수 구하기

	combination(0, 0, n, com, &min, parr);
	cout << min << '\n';

	for (int i = 0; i < n; i++) {
		delete[]arr[i];
		delete[] parr[i];
	}
	delete[] arr;
	delete[] parr;
	return 0;
}
