/**
 * @file 9184.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 신나는 함수 실행
 * @date 2023-02-25
 *
 * 재귀함수를 효율적으로 바꿔라
 * 결과값을 dp에 저장
 */
#include <iostream>

int dp[51][51][51] = {
	0,
};

int solve(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	if (dp[a][b][c]) {
		return dp[a][b][c];
	}
	if (a > 20 || b > 20 | c > 20) {
		dp[20][20][20] = solve(20, 20, 20);
		return dp[20][20][20];
	}

	dp[a - 1][b][c] = solve(a - 1, b, c);
	dp[a - 1][b - 1][c] = solve(a - 1, b - 1, c);
	dp[a - 1][b][c - 1] = solve(a - 1, b, c - 1);
	dp[a - 1][b - 1][c - 1] = solve(a - 1, b - 1, c - 1);

	return dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] -
		   dp[a - 1][b - 1][c - 1];
}

int main(void) {
	while (true) {
		int a, b, c;
		std::cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		std::cout << "w(" << a << ", " << b << ", " << c
				  << ") = " << solve(a, b, c) << std::endl;
	}
}
