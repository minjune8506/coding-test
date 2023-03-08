/**
 * @file 11399.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief ATM
 * @date 2023-03-08
 *
 * ATM앞에 N명의 사람들이 줄을 서있다.
 * 사람은 1번부터 N번까지 번호가 매겨져 있고, i번 사람이 돈을
 * 인출하는데 걸리는 시간은 Pi분이다.
 * SJF(Shortest-Job-First) 알고리즘을 이용한 문제인것 같다.
 * 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값
 */
#include <iostream>
#include <queue>
#include <vector>

int main(void) {
	std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
	int N;

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int time;
		std::cin >> time;
		pq.push(time);
	}

	int answer = 0;
	int curr = 0;
	while (!pq.empty()) {
		int time = pq.top();
		pq.pop();
		curr += time;
		answer += curr;
	}
	std::cout << answer << '\n';
}
