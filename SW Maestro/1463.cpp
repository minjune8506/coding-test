/**
 * @file 1463.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 1로 만들기
 * @date 2023-02-24
 *
 * 정수 X에 사용할 수 있는 연산
 * 1. X가 3으로 나누어 떨어지면 3으로 나눈다.
 * 2. X가 2로 나누어 떨어지면 2로 나눈다.
 * 3. 1을 뺀다.
 *
 * 정수 N이 주어질 때 위의 연산을 이용해 1을 만드려 한다.
 * 연산의 최솟값을 출력
 *
 * 1 <= N <= 10^6 (1,000,000)
 */
#include <iostream>
#include <algorithm>

int main(void) {
	int N;
	int dp[1000001];

	std::cin >> N;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= N; i++) {
		int count = dp[i - 1] + 1;
		if (!(i % 2)) {
			count = std::min(count, dp[i / 2] + 1);
		}
		if (!(i % 3)) {
			count = std::min(count, dp[i / 3] + 1);
		}
		dp[i] = count;
	}
	std::cout << dp[N] << std::endl;
}
