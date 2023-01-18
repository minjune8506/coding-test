/**
 * @file 10807.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 개수 세기
 * @date 2023-01-17
 * 
 * N개의 정수가 주어졌을 때, v가 몇개인지 구하기
 * 
 * N (1 <= N <= 100)
 */
#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> numbers;
	int count;

	std::cin >> count;
	for (int i = 0; i < count; i++) {
		int num;
		std::cin >> num;
		numbers.push_back(num);
	}

	int target;
	std::cin >> target;
	int answer = 0;

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == target) {
			answer++;
		}
	}

	std::cout << answer << std::endl;
}
