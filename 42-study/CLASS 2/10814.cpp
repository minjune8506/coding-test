/**
 * @file 10814.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 나이순 정렬
 * @date 2023-02-08
 *
 * 나이와 이름이 가입한 순서대로 주어진다.
 * 회원들의 나이가 증가하는 순으로, 같으면 먼저 가입한 사람이 앞에 오는 순서로
 * 정렬하는 프로그램
 */
#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
	int N;
	std::cin >> N;
	std::vector<std::pair<int, std::string> > users;

	for (int i = 0; i < N; i++) {
		std::pair<int, std::string> user;

		std::cin >> user.first >> user.second;
		users.push_back(user);
	}

	std::stable_sort(users.begin(), users.end(),
					 [](std::pair<int, std::string> front,
						std::pair<int, std::string> back) -> bool {
						 return front.first < back.first;
					 });

	for (auto user : users) {
		std::cout << user.first << ' ' << user.second << '\n';
	}
}
