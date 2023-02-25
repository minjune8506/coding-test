/**
 * @file 1920.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 수 찾기
 * @date 2023-02-24
 *
 * N개의 정수 A[1], A[2], ..., A[N]이 주어질때
 * X라는 정수가 있는지 알아내라
 *
 * 1 <= N <= 100,000
 * 1 <= M <= 100,000
 * 정수는 int 범위
 */
#include <iostream>
#include <unordered_map>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::unordered_map<int, bool> numbers;
	for (int i = 0; i < N; i++) {
		int number;

		std::cin >> number;
		numbers.insert(std::make_pair(number, true));
	}

	int M;
	std::cin >> M;
	for (int i = 0; i < M; i++) {
		int number;

		std::cin >> number;
		if (numbers.find(number) != numbers.end()) {
			std::cout << 1 << '\n';
			continue;
		}
		std::cout << 0 << '\n';
	}
}
