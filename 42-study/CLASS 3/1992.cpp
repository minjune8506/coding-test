/**
 * @file 1992.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 쿼드트리
 * @date 2023-02-22
 *
 * 흰 점 (0) 검은 점 (1)으로 이루어진 2차원 배열에서
 * 같은 숫자의 점들이 한 곳에 많이 몰려있으면 쿼드트리는 이를 압축 가능하다.
 *
 * 주어진 영상이 모두 0으로 되어있으면 압축 결과는 0
 * 모두 1로만 되어있으면 압축 결과는 1
 * 0과 1이 섞여있으면 4등분하여 압축하게 된다.
 *
 * NxN 크기의 영상을 압축현 결과를 출력
 *
 * N (2의 제곱수) 1 <= N <= 64
 *
 * 1001
 * 0101
 * 0011
 * 1100
 * ((1001)(0101)(0011)(1100))
 *
 * 재귀, 구간을 나누어 해결
 */
#include <iostream>
#include <vector>

std::string result;

bool canCompress(std::vector<char> &video, int x, int y, int range, int N) {
	char start = video[y * N + x];

	for (int i = y; i < y + range; i++) {
		for (int j = x; j < x + range; j++) {
			if (video[i * N + j] != start) {
				return false;
			}
		}
	}
	return true;
}

void solve(std::vector<char> &video, int x, int y, int range, int N) {
	if (range < 1) {
		return;
	}
	if (canCompress(video, x, y, range, N)) {
		result += (video[y * N + x]);
		return;
	}
	result += '(';
	solve(video, x, y, range / 2, N);
	solve(video, x + range / 2, y, range / 2, N);
	solve(video, x, y + range / 2, range / 2, N);
	solve(video, x + range / 2, y + range / 2, range / 2, N);
	result += ')';
}

int main(void) {
	int N;

	std::cin >> N;
	std::vector<char> video;
	for (int i = 0; i < N; i++) {
		std::string row;

		std::cin >> row;
		for (int j = 0; j < row.size(); j++) {
			video.push_back(row.at(j));
		}
	}
	solve(video, 0, 0, N, N);
	std::cout << result << std::endl;
}
