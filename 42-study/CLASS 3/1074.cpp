/**
 * @file 1074.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief Z
 * @date 2023-02-15
 *
 * 크기가 2^N x 2^N인 2차원 배열을 Z모양으로 탐색하려고 한다.
 * N > 1인 경우, 배열을 크기가 2 ^ N-1 x 2 ^ N-1로 4등분한 후 재귀적으로
 * 순서대로 방문한다.
 *
 * 1 <= N <= 15
 * 0 <= r, c < 2^N
 *
 * - N이 주어진다.
 * - 2^N x 2^N 배열을 만든다.
 * - 2^N / 2 x 2^N / 2 배열로 나눈다. (4등분)
 * - 왼쪽 위의 사각형부터 다시 나눌수 없을때까지 4등분을 한다.
 * - 순서대로 번호를 매긴다 (0, 1, 2, 3)
 * - 재귀를 빠져나와 다음 사각형 번호를 매긴다.
 * - r행 c열을 출력한다.
 *
 * 문제는 해결하였으나 메모리 초과!
 * - 배열을 선언하지 않고 풀 수 있는 방법은 없을까?
 * - r행 c열이 4등분을 했을때 어느 방향에 있는지를 알면 규칙이 있을 것 같다.
 * - 해결
 */

#include <cmath>
#include <iostream>

int solve(int x, int y, int width, int r, int c, int start) {
	if (width <= 1) {
		return start;
	}
	int box = width / 2 * width / 2;
	if (y <= r && r < y + width / 2) {
		if (x <= c && c < x + width / 2) {
			// 1사분면
			return solve(x, y, width / 2, r, c, start);
		} else {
			// 2사분면
			return solve(x + width / 2, y, width / 2, r, c, start + box);
		}
	} else {
		if (x <= c && c < x + width / 2) {
			// 3사분면
			return solve(x, y + width / 2, width / 2, r, c, start + box * 2);
		} else {
			// 4사분면
			return solve(x + width / 2, y + width / 2, width / 2, r, c,
						 start + box * 3);
		}
	}
}

int main(void) {
	int N, r, c;

	std::cin >> N >> r >> c;
	int width = std::pow(2, N);

	std::cout << solve(0, 0, width, r, c, 0) << std::endl;
}
