/**
 * @file 1780.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 종이의 개수
 * @date 2023-02-21
 *
 * NxN 크기의 행렬로 표현되는 종이가 있다.
 * 종이의 각 칸에는 -1, 0, 1중 하나가 저장되어 있다.
 *
 * 규칙에 따라 자른다.
 * 1. 만약 종이가 모두 같은 수로 되어 있다면 그대로 사용한다.
 * 2. (1)이 아닌 경우 종이를 같은 크기의 종이 9개로 자르고, 각각의 종이에 대해
 * (1)의 과정을 반복한다.
 *
 * 종이를 잘랐을 떄, -1, 0, 1로만 채워진 종이의 개수를 각각 구해라
 *
 * N (1 <= N <= 3^7)
 *
 * 범위를 나눠서 1의 규칙을 만족하는지 검사한다.
 * 만족하면 개수를 세고, 만족하지 않으면 9등분한다.
 */
#include <iostream>
#include <vector>

int count[3] = {
	0,
};

bool isPerfectPaper(std::vector<int> &paper, int x, int y, int size, int N) {
	int previous = paper[y * N + x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (previous != paper[i * N + j]) {
				return false;
			}
		}
	}
	return true;
}

void solve(std::vector<int> &paper, int x, int y, int size, int N) {
	if (isPerfectPaper(paper, x, y, size, N)) {
		count[paper[y * N + x] + 1]++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(paper, x + size / 3 * j, y + size / 3 * i, size / 3, N);
		}
	}
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N;

	std::cin >> N;
	std::vector<int> paper;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int number;

			std::cin >> number;
			paper.push_back(number);
		}
	}
	solve(paper, 0, 0, N, N);
	std::cout << count[0] << '\n' << count[1] << '\n' << count[2] << '\n';
}
