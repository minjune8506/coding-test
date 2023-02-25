/**
 * @file 10844.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 쉬운 계단 수
 * @date 2023-02-24
 *
 * 45656
 * 인접한 모든 자리의 차이가 1이다.
 * 이런 수를 계단수라고 한다.
 * N이 주어질때, 길이가 N인 계단 수가 몇개있는지 구해보자.
 * 0으로 시작하면 안됨.
 *
 * 정답을 1,000,000,000 (10억)으로 나눈 나머지 출력
 * 1 <= N <= 100
 *
 * DP 문제
 * - 각 자릿수로 끝나는 수들이 어떤 것들이 있는지 살펴보고 점화식을 세운다.
 * - 모듈러 연산 수행
 * - 난이도 최상
 * - 정답봐도 잘 이해안감
 */
#include <cstring>
#include <iostream>

int main(void) {
	int N;

	std::cin >> N;

	long long dp[N][10];
	memset(dp, 0, sizeof(long long) * (N * 10));

	for (int i = 0; i < 10; i++) {
		dp[0][i] = 1;
	}
	dp[0][0] = 0;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			} else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			} else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] % 1000000000;
			}
		}
	}

	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[N - 1][i];
		sum %= 1000000000;
	}
	std::cout << sum << std::endl;
}
