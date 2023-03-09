/**
 * @file 11659.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 구간 합 구하기 4
 * @date 2023-03-09
 *
 * 수 N개가 주어졌을 때, i번째 수부터 j번째 수까지의 합을 구하는 프로그램
 */
#include <iostream>
#include <vector>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;

	std::cin >> N >> M;
	std::vector<int> numbers;

	numbers.push_back(0);
	for (int i = 1; i <= N; i++) {
		int number;
		std::cin >> number;
		numbers.push_back(numbers[i - 1] + number);
	}

	for (int i = 0; i < M; i++) {
		int start, end;
		std::cin >> start >> end;
		std::cout << numbers[end] - numbers[start - 1] << '\n';
	}
}
