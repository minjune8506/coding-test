/**
 * @file 2420.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 사파리월드
 * @date 2023-01-16
 * 
 * 두 도메인의 유명도가 주어졌을 때 그 차이를 구하는 프로그램을 작성
 * 
 * 유명도 N, M
 * -2,000,000,000 <= N, M <= 2,000,000,000
 * 
 * | N - M | 을 출력
 */

#include <iostream>

int main(void) {
	long long N, M;
	std::cin >> N >> M;

	long long result;
	result = (N > M) ? N - M : M - N;
	std::cout << result << std::endl;
}
