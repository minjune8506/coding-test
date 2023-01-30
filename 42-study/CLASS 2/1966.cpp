/**
 * @file 1966.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 프린터 큐
 * @date 2023-01-30
 *
 * 1. 현재 Queue의 가장 앞에 있는 문서의 중요도를 확인한다.
 * 2. 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면
 * 이 문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치한다.
 * 3. 없다면 인쇄를 한다.
 *
 * Queue에 있는 문서의 수와 중요도가 주어질 때
 * 어떤 한 문서가 몇번째로 인쇄되는지 알아내라
 *
 * 문서의 개수 N 1 <= N <= 100
 * 몇 번째로 인쇄되었는지 궁금한 문서가 현재 Queue에서
 * 몇 번째로 놓여 있는지를 타내는 정수 M (0 <= M < N)
 *
 * 맨 왼쪽은 0이라고 한다.
 * 중요도는 1이상 9이하의 정수이고, 중요도가 같은 문서가 여러개 존재 가능
 */
#include <deque>
#include <iostream>

bool isFirstPriority(std::deque<int> queue) {
	int front = queue.front();
	for (int i = 1; i < queue.size(); i++) {
		if (queue[i] > front) {
			return false;
		}
	}
	return true;
}

void solve() {
	int documentCount, targetIndex;
	std::deque<int> queue;

	std::cin >> documentCount >> targetIndex;
	for (int i = 0; i < documentCount; i++) {
		int priority;

		std::cin >> priority;
		queue.push_back(priority);
	}

	int count = 1;
	while (!queue.empty()) {
		int front = queue.front();
		bool canPop = isFirstPriority(queue);

		if (!canPop) {
			// rotate
			queue.push_back(front);
			queue.pop_front();
		} else {
			if (targetIndex == 0) {
				std::cout << count << std::endl;
				return;
			}
			queue.pop_front();
			count++;
		}
		targetIndex--;
		if (targetIndex < 0) {
			targetIndex = queue.size() - 1;
		}
	}
}

int main(void) {
	int testCount;
	std::cin >> testCount;
	for (int i = 0; i < testCount; i++) {
		solve();
	}
}
