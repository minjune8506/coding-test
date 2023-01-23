/**
 * @file 3052.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 나머지
 * @date 2023-01-23
 * 
 * A % B는 A를 B로 나눈 나머지이다.
 * 수 10개를 입력받고 이를 42로 나눈 나머지를 구한다.
 * 서로 다른 값이 몇 개 있는지 출력하는 프로그램
 */
#include <iostream>
#include <vector>

int counts[42];

int main(void) {
	std::vector<int> numbers;

	for (int i = 0; i < 10; i++) {
		int number;
		std::cin >> number;

		numbers.push_back(number);
	}

	for (auto &number : numbers) {
		number %= 42;
		counts[number]++;
	}

	int answer = 0;
	for (auto count : counts) {
		if (count > 0) {
			answer++;
		}
	}

	std::cout << answer << std::endl;
}
