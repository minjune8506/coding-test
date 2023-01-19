/**
 * @file 2475.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 검증수
 * @date 2023-01-19
 * 
 * 컴퓨터 고유번호의 처음 5자리는 00000 ~ 99999까지의 수가 주어지며
 * 6번째 자리에는 검증수가 들어간다.
 * 
 * 검증수는 고유번호의 처음 5개 숫자의 제곱의 합을 10으로 나눈 나머지
 * 검증수를 출력하라
 */
#include <iostream>
#include <vector>
#include <cmath>

int main(void) {
	std::vector<int> serialNumbers;

	for (int i = 0; i < 5; i++) {
		int serialNumber;

		std::cin >> serialNumber;
		serialNumbers.push_back(serialNumber);
	}

	int sum = 0;
	for (auto serialNumber : serialNumbers) {
		sum += std::pow(serialNumber, 2);
	}
	std::cout << sum % 10 << std::endl;
}
