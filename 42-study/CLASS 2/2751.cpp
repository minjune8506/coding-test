/**
 * @file 2751.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 수 정렬하기 2
 * @date 2023-02-03
 * 
 * N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램
 * 1 <= N <= 1,000,000
 * 각 수는 절대값이 1,000,000보다 작거나 같은 정수이다.
 */
#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {
	int numberCount;
	std::vector<int> numbers;

	std::cin >> numberCount;
	for (int i = 0; i < numberCount; i++) {
		int number;

		std::cin >> number;
		numbers.push_back(number);
	}
	
	std::sort(numbers.begin(), numbers.end());
	for (auto number : numbers) {
		std::cout << number << '\n';
	}
}
