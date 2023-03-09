/**
 * @file 11723.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 집합
 * @date 2023-03-09
 *
 * add x : S에 x를 추가 (1 <= x <= 20) 이미 있는 경우 연산 무시
 * remove x : S에 x를 제거 (1 <= x <= 20) x가 없는 경우 무시
 * check x : S에 x가 있으면 1 없으면 0 출력 (1 <= x <= 20)
 * toggle x : S에 x가 있으면 제거 / 없으면 x를 추가 (1 <= x <= 20)
 * all: S를 {1, 2, ..., 20}으로 바꾼다.
 * empty: S를 공집합으로 바꾼다.
 */
#include <iostream>
#include <set>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int M;
	std::cin >> M;

	std::set<int> s;

	std::set<int> temp;
	for (int i = 1; i <= 20; i++) {
		temp.insert(i);
	}

	for (int i = 0; i < M; i++) {
		std::string cmd;
		std::cin >> cmd;

		int x;

		if (cmd == "add") {
			std::cin >> x;
			s.insert(x);
		} else if (cmd == "remove") {
			std::cin >> x;
			s.erase(x);
		} else if (cmd == "check") {
			std::cin >> x;
			auto found = s.find(x);
			std::cout << (found != s.end() ? 1 : 0) << '\n';
		} else if (cmd == "toggle") {
			std::cin >> x;
			auto found = s.find(x);
			if (found != s.end()) {
				s.erase(x);
			} else {
				s.insert(x);
			}
		} else if (cmd == "all") {
			s = temp;
		} else if (cmd == "empty") {
			s.clear();
		}
	}
}
