/**
 * @file 15964.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 이상한 기호
 * @date 2023-01-17
 * 
 * A@B = (A + B) x (A - B)로 정의한다고 하자
 * A, B가 주어지면 A@B를 계산하는 프로그램
 * 
 * 1 <= A, B <= 100,000
 */
#include <iostream>

int main(void) {
	int A, B;

	std::cin >> A >> B;
	std::cout << (long long)(A + B) * (A - B) << std::endl;
}
