/**
 * @file 7662.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 이중 우선순위 큐
 * @date 2023-03-04
 *
 * 이중 우선순위 큐는 데이터를 삭제할때 연산 명령에 따라
 * 우선순위가 가장 높은 데이터 또는 가장 낮은 데이터 중 하나를
 * 삭제한다.
 *
 * Q에 적용할 연산의 개수 k (k <= 1,000,000)
 * D / I 연산 정수 n
 *
 * map 이용 -> red black tree (시간초과)
 * muti-map 이용 -> 풀리긴 할듯
 * multi-set 사용 -> 키값이 중복돼도 괜찮음
 *
 * max_element를 사용하면 안됨. iterator로 접근
 */
#include <iostream>
#include <set>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int testCase;
	std::cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		std::multiset<int> ms;

		int commandCount;
		std::cin >> commandCount;

		for (int i = 0; i < commandCount; i++) {
			char operation;
			int target;

			std::cin >> operation >> target;

			if (operation == 'I') {
				ms.insert(target);
			} else {
				if (!ms.empty()) {
					if (target > 0) {
						auto iter = ms.end();
						iter--;
						ms.erase(iter);
					} else {
						ms.erase(ms.begin());
					}
				}
			}
		}

		if (ms.empty()) {
			std::cout << "EMPTY" << '\n';
		} else {
			std::cout << *(ms.rbegin()) << ' ' << *(ms.begin()) << '\n';
		}
	}
}
