/**
 * @file 11866.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 요세푸스 문제 0
 * @date 2023-02-12
 *
 * 1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수
 * K(<= N)가 주어진다.
 *
 * 순서대로 K번째 사람을 제거한다.
 * 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 과정을 계속한다.
 *
 * N명이 모두 제거될때까지 계속한다.
 * 제거되는 순서를 구하라
 *
 * - N명을 queue에 넣는다.
 * - K번째 사람을 제거한다.
 * - 반복한다.
 */
#include <iostream>
#include <queue>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, K;

	std::cin >> N >> K;
	std::queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	int count = 0;
	std::cout << '<';
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		count++;
		if (count == K) {
			std::cout << front;
			if (!q.empty()) {
				std::cout << ", ";
			}
			count = 0;
		} else {
			q.push(front);
		}
	}
	std::cout << '>' << std::endl;
}
