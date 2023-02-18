/**
 * @file 1463.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 1로 만들기
 * @date 2023-02-17
 *
 * 정수 X에 사용할 수 있는 연산
 * 1. X가 3으로 나누어 떨어지면 3로 나눈다.
 * 2. X가 2으로 나누어 떨어지면 2로 나눈다.
 * 3. 1을 뺀다.
 *
 * 정수 N이 주어졌을때 위의 연산 세개를 이용해서 1을 만들고
 * 연산의 최소 횟수를 출력해라.
 *
 * 1 <= N <= 10^6
 *
 * - if문으로 풀어보려고 시도함 -> 실패..
 * - 질문 게시판을 들어갔다가 DP 문제라는걸 알게됨
 * - 왜 DP로..? 재귀적으로 완전탐색하는 문제?
 * - 재귀적으로 모든 경우를 탐색하니 겹치는 경우가 많음
 * - N의 범위가 10^6까지 가는 것을 보니 완전탐색은 시간초과가 날것 같음
 * - 10^6 -> 1,000,000 * 4  -> 4MB ? 저장할수 있을듯
 * - 10^6도 오랜 시간이 걸리지 않음.
 * - 마지막(99%)에서 틀렸다고 나옴 -> 1일때는 0인데 실수를 함.. 해결!
 */
#include <algorithm>
#include <iostream>
#include <vector>

long long N;
std::vector<int> counts;

void solve(int N, int count, long long dp[]) {
	if (dp[N]) {
		counts.push_back(count + dp[N]);
		return;
	}
	if (N == 1) {
		counts.push_back(count);
		return;
	}
	if (N % 2 == 0) {
		solve(N / 2, count + 1, dp);
	}
	if (N % 3 == 0) {
		solve(N / 3, count + 1, dp);
	}
	solve(N - 1, count + 1, dp);
}

int main(void) {
	long long N;

	std::cin >> N;
	long long dp[N + 1];
	for (int i = 0; i < N + 1; i++) {
		dp[i] = 0;
	}
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= N; i++) {
		solve(i, 0, dp);
		dp[i] = *(std::min_element(counts.begin(), counts.end()));
		counts.clear();
	}
	std::cout << dp[N] << std::endl;
}
