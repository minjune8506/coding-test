/**
 * @file 1008.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief A / B
 * @date 2023-01-18
 * 
 * A, B를 입력받아 A / B를 출력하는 프로그램
 * 
 * 0 < A, B < 10
 */
#include <iostream>
#include <iomanip>

int main(void) {
	double A, B;

	std::cin >> A >> B;
	std::cout << std::setprecision(10) << A / B << std::endl;
}
