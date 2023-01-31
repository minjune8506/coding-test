/**
 * @file 1978.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 소수 찾기
 * @date 2023-01-31
 * 
 * 주어진 수 N개 중에서 소수가 몇개인지 찾아서 출력하라
 * 
 * N은 100이하이다.
 * 수는 1000이하의 자연수이다.
 * 
 */
#include <iostream>

bool isPrimeNumber(int number) {
	if (number < 2) {
		return false;
	}
	for (int i = 2; i * i <= number; i++) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int numberCount;
	int primeNumberCount = 0;

	std::cin >> numberCount;
	for (int i = 0; i < numberCount; i++) {
		int number;

		std::cin >> number;
		if (isPrimeNumber(number)) {
			primeNumberCount++;
		}
	}
	std::cout << primeNumberCount << std::endl;
}
