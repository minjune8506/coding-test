/**
 * @file 2753.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 윤년
 * @date 2023-01-23
 * 
 * 윤년이면 1, 아니면 0을 출력하는 프로그램
 * 
 * 윤년은 4의 배수, 100의 배수가 아닐 때 또는 400의 배수일때.
 */
#include <iostream>

int main(void) {
	int year;

	std::cin >> year;
	if (year % 4 == 0 && year % 100) {
		std::cout << 1 << std::endl;
	} else if (year % 400 == 0) {
		std::cout << 1 << std::endl;
	} else {
		std::cout << 0 << std::endl;
	}
}
