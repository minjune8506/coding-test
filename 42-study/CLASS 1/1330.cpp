/**
 * @file 1330.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 두 수 비교하기
 * @date 2023-01-19
 * 
 * 두 정수 A와 B가 주어졌을 때, A, B를 비교
 * A와 B는 공백 한 칸으로 구분된다.
 * 
 * 출력
 * A > B : >
 * A < B : <
 * A == B : ==
 * 
 * -10,000 <= A, B <= 10,000
 */

#include <iostream>

int main(void) {
	int A, B;

	std::cin >> A >> B;
	if (A > B) {
		std::cout << ">" << std::endl;
	} else if (A < B) {
		std::cout << "<" << std::endl;
	} else {
		std::cout << "==" << std::endl;	
	}
}
