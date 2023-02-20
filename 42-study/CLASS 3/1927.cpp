/**
 * @file 1927.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 최소 힙
 * @date 2023-02-21
 *
 * 1. 배열에 자연수 x를 넣는다.
 * 2. 배열에서 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
 *
 * 연산의 개수 N (1 <= N <= 100,000)
 * 정수 x (x > 0) push
 * x == 0 pop
 * 0 <= x < 2^31
 *
 * 배열이 비어있는 경우 0을 출력해야 한다.
 */
#include <iostream>
#include <queue>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::priority_queue<int, std::vector<int>, std::greater<int> > que;
	int N;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int number;

		std::cin >> number;
		if (number) {
			que.push(number);
			continue;
		}
		if (que.empty()) {
			std::cout << 0 << '\n';
			continue;
		}
		std::cout << que.top() << '\n';
		que.pop();
	}
}
