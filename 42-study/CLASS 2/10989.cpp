/**
 * @file 10989.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 수 정렬하기 3
 * @date 2023-02-10
 *
 * N개의 수가 주어졌을 때, 오름차순으로 정렬해라
 */
#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;

	std::cin >> N;
	int numbers[10001] = {
		0,
	};
	for (int i = 0; i < N; i++) {
		int number;

		std::cin >> number;
		numbers[number]++;
	}

	for (int i = 0; i < 10001; i++) {
		if (numbers[i] > 0) {
			int count = numbers[i];
			while (count) {
				std::cout << i << '\n';
				count--;
			}
		}
	}
}
