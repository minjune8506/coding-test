/**
 * @file 2407.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 조합
 * @date 2023-03-24
 * nCm 출력
 * (5 <= n <= 100, 5 <= m <= 100, m <= n)
 *
 * nCk =
 *   n!
 * -------
 * k!(n-k)!
 *
 * 파스칼의 삼각형 이용
 * 문자열 덧셈 구현
 */
#include <algorithm>
#include <iostream>

std::string dp[101][101];

std::string add(std::string x, std::string y) {
	int temp = 0;
	std::string result = "";

	while (!x.empty() || !y.empty() || temp) {
		if (!x.empty()) {
			temp += (x.back() - '0');
			x.pop_back();
		}
		if (!y.empty()) {
			temp += (y.back() - '0');
			y.pop_back();
		}
		result.push_back((temp % 10) + '0');
		temp /= 10;
	}
	std::reverse(result.begin(), result.end());
	return result;
}

std::string combination(int N, int M) {
	if ((N == 0 || M == 0) || N == M) {
		return "1";
	}
	if (dp[N][M] != "") {
		return dp[N][M];
	}

	dp[N][M] = add(combination(N - 1, M - 1), combination(N - 1, M));
	return dp[N][M];
}

int main(void) {
	int N, M;
	std::cin >> N >> M;

	std::cout << combination(N, M) << '\n';
}
