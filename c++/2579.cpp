#include <iostream>
#include <algorithm>

using namespace std;
int main(void) {
	int n, temp;
	int* score, * maxscore;
	bool* visited;
	cin >> n;
	score = new int[n + 1];
	maxscore = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> score[i];
	}
	if (n == 1) {
		cout << score[1];
		return 0;
	}
	if (n == 2) {
		cout << score[1]+score[2];
		return 0;
	}
	maxscore[1] = score[1];
	maxscore[2] = score[1] + score[2];
	maxscore[3] = max(score[1] + score[3], score[2] + score[3]);
	for (int i = 4; i <= n; i++) {
		maxscore[i] = max(maxscore[i - 2] + score[i], score[i - 1] + score[i] + maxscore[i - 3]);
	}
	cout << maxscore[n];
	delete[] score;
	delete[]maxscore;
	return 0;
}
