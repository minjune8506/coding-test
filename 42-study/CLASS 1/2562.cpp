/**
 * @file 2562.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 최댓값
 * @date 2023-01-20
 * 
 * 9개의 서로 다른 자연수.
 * 최댓값을 찾고 몇 번째 수인지 구하는 프로그램
 * 
 * 자연수는 100보다 작다.
 */
#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> numbers;

	for (int i = 0; i < 9; i++) {
		int number;
		std::cin >> number;
		numbers.push_back(number);
	}

	int maxIndex = 0;
	for (int i = 1; i < numbers.size(); i++) {
		if (numbers[i] > numbers[maxIndex]) {
			maxIndex = i;
		}
	}

	std::cout << numbers[maxIndex] << '\n' << maxIndex + 1 << std::endl;
}
