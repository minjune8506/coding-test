/**
 * @file 11047.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 동전 0
 * @date 2023-03-06
 *
 * 동전을 N 종류를 가지고 있다.
 * 각각의 동전은 많이 가지고 있다.
 *
 * 동전을 적절히 사용해 가치의 합을 K로 만드려고 한다.
 * 필요한 동전 개수의 최솟값을 구해라
 *
 * 1 <= N <= 10
 * 1 <= K <= 100,000,000
 *
 * 1 <= Ai <= 1,000,000
 * A1 = 1, i >= 2인 경우 Ai는 Ai-1의 배수
 *
 * 그리디 문제
 */
#include <iostream>
#include <vector>

int main(void) {
	int N, K;

	std::cin >> N >> K;

	std::vector<int> coins;
	for (int i = 0; i < N; i++) {
		int coin;

		std::cin >> coin;
		coins.push_back(coin);
	}

	int answer = 0;
	int index = coins.size() - 1;
	while (K != 0) {
		answer += K / coins[index];
		K = K % coins[index];
		index--;
	}

	std::cout << answer << '\n';
	
}
