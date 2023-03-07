/**
 * @file 11286.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 절댓값 힙
 * @date 2023-03-07
 *
 * 1. 배열에 정수 x (x != 0)을 넣는다.
 * 2. 배열에서 절댓값이 가장 작은 값을 출력, 그 값을 배열에서 제거 여러개일 경우
 * 가장 작은 수를 출력
 */
#include <iostream>
#include <queue>
#include <vector>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	auto comp = [](int x, int y) -> bool {
		if (std::abs(x) == std::abs(y)) {
			return x > y;
		}
		return std::abs(x) > std::abs(y);
	};

	std::priority_queue<int, std::vector<int>, decltype(comp)> pq(comp);

	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int oper;

		std::cin >> oper;
		if (!oper) {
			if (pq.empty()) {
				std::cout << 0 << '\n';
			} else {
				std::cout << pq.top() << '\n';
				pq.pop();
			}
		} else {
			pq.push(oper);
		}
	}
}
