/**
 * @file 2908.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 상수
 * @date 2023-01-23
 * 
 * 세 자리 수 두 개가 주어진다.
 * 예를 들어 734와 893이 주어지면, 두 수를 반대로 읽는다.
 * 437 398이 되고 더 큰 수는 437이 된다.
 */
#include <iostream>
#include <algorithm>

int main(void) {
	std::string A, B;

	std::cin >> A >> B;
	std::reverse(A.begin(), A.end());
	std::reverse(B.begin(), B.end());
	int reversedA = std::stoi(A);
	int reversedB = std::stoi(B);

	std::cout << (reversedA > reversedB ? reversedA : reversedB) << std::endl;
}
