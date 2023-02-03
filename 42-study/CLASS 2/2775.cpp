/**
 * @file 2775.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 부녀회장이 될테야
 * @date 2023-02-03
 *
 * 아파트에 거주하려면 조건이 있다.
 * a층의 b호에 살려면 자신의 아래(a-1)층의 1호부터 b호까지 사람들의
 * 수의 합만큼 사람들을 데려와 살아야 한다.
 *
 * 아파트에 비어있는 집은 없고 모든 거주민들이 이 계약 조건을
 * 지키고 왔다고 가정했을때,
 * k층의 n호에는 몇명이 살고 있는지 출력해라
 *
 * 아파트는 0층부터 있고, 각 층에는 1호부터 있다.
 * 0층의 i호에는 i명이 산다.
 *
 * 1 5 15 35 70 ...
 * 1 4 10 20 35
 * 1 3 6 10 15
 * 1 2 3 4 5
 *
 * - 재귀적으로 해결
 * - DP를 이용해서 미리 계산후 풀어도 됨
 */
#include <iostream>

int solve(int k, int n) {
	if (k == 0) {
		return n;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum = sum + solve(k - 1, i);
	}
	return (sum);
}

int main(void) {
	int testCaseCount;

	std::cin >> testCaseCount;
	for (int i = 0; i < testCaseCount; i++) {
		int k, n;

		std::cin >> k >> n;
		std::cout << solve(k, n) << std::endl;
	}
}
