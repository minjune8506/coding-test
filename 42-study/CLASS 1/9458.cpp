/**
 * @file 9458.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 시험 성적
 * @date 2023-01-23
 * 
 * 90 ~ 100 : A
 * 80 ~ 89 : B
 * 70 ~ 79 : C
 * 60 ~ 69 : D
 * F
 */

#include <iostream>

int main(void) {
	int grade;
	std::cin >> grade;

	if (90 <= grade) {
		std::cout << 'A' << std::endl;
	} else if (80 <= grade) {
		std::cout << 'B' << std::endl;
	} else if (70 <= grade) {
		std::cout << 'C' << std::endl;
	} else if (60 <= grade) {
		std::cout << 'D' << std::endl;
	} else {
		std::cout << 'F' << std::endl;
	}
}
