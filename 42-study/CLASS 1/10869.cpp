/**
 * @file 10869.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 사칙연산
 * @date 2023-01-23
 * 
 * 자연수 A와 B가 주어진다.
 * A + B
 * A - B
 * A * B
 * A / B
 * A % B를 출력하라
 */

#include <iostream>

int main(void) {
	int A, B;
	std::cin >> A >> B;

	std::cout << A + B << '\n'
			<< A - B  << '\n'
			<< A * B  << '\n'
			<< A / B  << '\n'
			<< A % B  << std::endl;
}
