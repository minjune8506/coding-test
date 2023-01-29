/**
 * @file 1920.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 수 찾기
 * @date 2023-01-29
 *
 * N개의 정수 A[1], A[2], ..., A[N]이 주어질때
 * X라는 정수가 존재하는지 알나내느 프로그램
 *
 * 1 <= N <= 100,000
 * 1 <= M <= 100,000
 *
 * M개의 수들 중 A가 존재하는지 알아보면 된다.
 *
 * 시간 초과
 * - 정렬된 상태로 저장하면 해결되지 않을까? (set 이용)
 *  -> 시간 초과
 * - 출력에 시간이 오래 걸리는 건 아닐까? (std::ios::sync_with_stdio(false))
 *  -> 시간 초과
 * - 출력에 std::endl 를 많이 써서 flush때문에 속도가 느리다?
 *  -> 해결 (O)
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::set<int> numbersGroupA;
	std::vector<int> numbersGroupB;

	int N, M;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int number;

		std::cin >> number;
		numbersGroupA.insert(number);
	}
	std::cin >> M;
	for (int i = 0; i < M; i++) {
		int number;

		std::cin >> number;
		numbersGroupB.push_back(number);
	}

	for (auto toFind : numbersGroupB) {
		if (numbersGroupA.find(toFind) != numbersGroupA.end()) {
			std::cout << "1" << '\n';
			continue;
		}
		std::cout << "0" << '\n';
	}
	std::cout << std::endl;
}
