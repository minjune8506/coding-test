/**
 * @file 2164.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 카드2
 * @date 2023-02-01
 *
 * N장의 카드가 있다.
 * 각각의 카드는 차례로 1부터 N까지의 번호가 붙어 있고 1번 카드가
 * 제일 위에 있다.
 *
 * - 제일 위에 있는 카드를 바닥에 버린다.
 * - 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.
 *
 * 마지막에 남게되는 카드를 구하라
 */
#include <iostream>
#include <queue>

int main(void) {
	std::queue<int> queue;
	int cardCount;

	std::cin >> cardCount;
	for (int i = 1; i <= cardCount; i++) {
		queue.push(i);
	}

	while (true) {
		int removed = queue.front();
		queue.pop();
		if (queue.empty()) {
			std::cout << removed << std::endl;
			break;
		}
		queue.push(queue.front());
		queue.pop();
	}
}
