/**
 * @file 11382.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 꼬마 정민
 * @date 2023-01-16
 * 
 * A + B + C의 값을 출력한다.
 * 1 <= A, B, C <= 10^12
 * 
 * - overflow 주의
 */

#include <iostream>

int main(void) {
	unsigned long long A, B, C;
	std::cin >> A >> B >> C;
	std::cout << A + B + C << std::endl;
}
