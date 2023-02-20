/**
 * @file 1764.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 듣보잡
 * @date 2023-02-20
 *
 * 듣도 못한 사람의 명단
 * 보도 못한 사람의 명단이 주어질 때
 * 듣도 보도 못한 사람의 명단을 구해라
 *
 * 듣도 못한 사람의 수 (N)
 * 보도 못한 사람의 수 (M)
 * 0 < N, M <= 500,000
 *
 * 이름의 길이는 20이하
 *
 * - map을 활용하면 되는 문제
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;
	std::unordered_map<std::string, int> didntSee;

	for (int i = 0; i < N; i++) {
		std::string name;

		std::cin >> name;
		didntSee.insert(std::make_pair(name, i));
	}

	std::vector<std::string> answer;

	for (int j = 0; j < M; j++) {
		std::string name;

		std::cin >> name;
		if (didntSee.find(name) != didntSee.end()) {
			answer.push_back(name);
		}
	}

	std::sort(answer.begin(), answer.end());
	std::cout << answer.size() << '\n';
	for (auto name : answer) {
		std::cout << name << '\n';
	}
}
