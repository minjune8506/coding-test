/**
 * @file 15652.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief N과 M (4)
 * @date 2023-03-24
 *
 * 자연수 N과 M이 주어였을때 조건을 만족하는 길이가 M인 수열을 구해라
 *
 * - 1부터 N까지 자연수 중 M개를 고른 수열
 * - 같은 수를 여러번 골라도 된다.
 * - 고른 수열은 비내림차순
 * 	- A1 <= A2 <= ... <= Ak-1 <= Ak : 비내림차순
 */
#include <iostream>

int N, M;
int ary[9];

void solve(int cnt, int curr) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			std::cout << ary[i] << ' ';
		}
		std::cout << '\n';
		return;
	}

	for (int i = curr; i <= N; i++) {
		ary[cnt] = i;
		solve(cnt + 1, i);
	}
}

int main(void) {
	std::cin >> N >> M;
	solve(0, 1);
}
