/**
 * @file 9663.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief N-Queen
 * @date 2023-04-19
 *
 * NxN 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
 * N이 주어졌을때 퀸을 놓는 방법의 수를 구해라
 *
 * 1 <= N < 15
 *
 * Queen은 대각선 / 가로 / 세로로 움직일 수 있음
 * DFS 이용
 */
#include <iostream>

int count;
int N;
int map[15];

bool check(int row) {
	for (int i = 0; i < row; i++) {
		if (map[i] == map[row] || std::abs(map[i] - map[row]) == row - i) {
			return false;
		}
	}
	return true;
}

void solve(int row) {
	if (row == N) {
		count++;
		return;
	}
	for (int i = 0; i < N; i++) {
		map[row] = i;
		if (check(row)) {
			solve(row + 1);
		}
		map[row] = 0;
	}
}

int main(void) {
	std::cin >> N;
	solve(0);
	std::cout << count << '\n';
}
