/**
 * @file 24416.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 피보나치 수 1
 * @date 2023-05-04
 */
#include <iostream>

int cnt, count;

int fib(int n) {
	if (n == 1 || n == 2) {
		cnt++;
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n) {
	int dp[n + 1];

	dp[1] = dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		count++;
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int main(void) {
	int N;
	std::cin >> N;
	fib(N);
	fibonacci(N);
	std::cout << cnt << ' ' << count << '\n';
}
