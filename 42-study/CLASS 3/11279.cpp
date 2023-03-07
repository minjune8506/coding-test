/**
 * @file 11279.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 최대 힙
 * @date 2023-03-07
 *
 * 1. 배열에 자연수 x를 넣는다.
 * 2. 배열에서 가장 큰 값을 출력하고 그 값을 제거한다.
 * max heap 이용
 *
 * 1 <= N <= 100,000
 * x : 자연수 -> 추가
 * 0 : 삭제
 * 비어있는데 삭제 -> 0 출력
 */
#include <iostream>
#include <queue>
#include <vector>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::priority_queue<int, std::vector<int>, std::less<int> > maxHeap;

	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int oper;

		std::cin >> oper;
		if (!oper) {
			if (maxHeap.empty()) {
				std::cout << 0 << '\n';
			} else {
				std::cout << maxHeap.top() << '\n';
				maxHeap.pop();
			}
		}
		if (oper) {
			maxHeap.push(oper);
		}
	}
}
