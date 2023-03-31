/**
 * @file 1629.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 곱셈
 * @date 2023-03-31
 *
 * 자연수 A를 B번 곱한 수를 알고싶다.
 * C로 나눈 나머지를 구하는 프로그램
 *
 * A, B, C는 모두 int 범위
 */
#include <iostream>

long long multiple(long long A, long long B, long long C) {
	if (B == 0) {
		return 1;
	}
	long long temp = multiple(A, B / 2, C);
	temp = temp * temp % C;
	if (B % 2) {
		return temp * A % C;
	} else {
		return temp;
	}
}

int main(void) {
	long long A, B, C;
	std::cin >> A >> B >> C;
	std::cout << multiple(A, B, C) << '\n';
}
