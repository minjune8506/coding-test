/**
 * @file 10818.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 최소, 최대
 * @date 2023-01-23
 * 
 * N개의 정수가 주어진다.
 * 최댓값과 최솟값을 구하는 프로그램
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	std::vector<int> numbers;
	int N;

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int number;
		std::cin >> number;

		numbers.push_back(number);
	}

	std::sort(numbers.begin(), numbers.end());
	std::cout << numbers[0] << ' ' << numbers[numbers.size() - 1] << std::endl;
}
