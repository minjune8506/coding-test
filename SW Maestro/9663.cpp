/**
 * @file 9663.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief N-Queen
 * @date 2023-02-25
 *
 * N x N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제
 * N이 주어졌을 때, 퀸을 놓는 방법의 수
 */
#include <iostream>

int N;

int ary[15][15];
int visited[15][15];

void solve() {
	for (int i = 0; i < N; i++) {
		ary[0][i] = 1;
		visited[0][i] = true;
	}
}

int main(void) { std::cin >> N; }
