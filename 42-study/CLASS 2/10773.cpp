/**
 * @file 10773.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 제로
 * @date 2023-02-07
 *
 * 잘못된 수를 부를 때마다 0을 외쳐서, 가장 최근에 쓴 수를 지운다.
 * 모든 수를 받아 적은 후 그 수의 합을 알고 싶어한다.
 */
#include <iostream>
#include <vector>

int main(void) {
	int K;
	std::cin >> K;
	std::vector<int> numbers;

	for (int i = 0; i < K; i++) {
		int number;

		std::cin >> number;
		if (number) {
			numbers.push_back(number);
			continue;
		}
		numbers.pop_back();
	}
	int sum = 0;
	for (auto number : numbers) {
		sum += number;
	}
	std::cout << sum << std::endl;
}
