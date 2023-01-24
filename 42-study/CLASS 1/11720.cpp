/**
 * @file 11720.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 숫자의 합
 * @date 2023-01-24
 * 
 * N개의 숫자가 공백 없이 쓰여있다.
 * 
 * 이 숫자를 모두 합해서 출력하는 프로그램
 * 숫자의 개수 N (1 <= N <= 100)
 */

#include <iostream>

int main(void) {
	int N;

	std::cin >> N;
	int sum = 0;
	std::string number;

	std::cin >> number;
	for (int j = 0; j < number.length(); j++) {
		sum += (number.at(j) - '0');
	}
	std::cout << sum << std::endl;
}
