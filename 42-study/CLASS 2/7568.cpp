/**
 * @file 7568.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 덩치
 * @date 2023-02-06
 *
 * 몸무게가 x kg이고 키가 y cm라면 이 사람의 덩치는 (x, y)로 표시된다.
 * 두 사람 A와 B의 덩치가 각각 (x, y), (p, q)라고 할때
 * x > p 그리고 y > q라면 우리는 A의 덩치가 B의 덩치보다 더 크다라고 한다.
 *
 */
#include <iostream>
#include <vector>

int main(void) {
	std::vector<std::pair<int, int> > people;
	int N;

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::pair<int, int> data;
		std::cin >> data.first >> data.second;
		people.push_back(data);
	}

	for (int i = 0; i < people.size(); i++) {
		int rank = 1;
		for (int j = 0; j < people.size(); j++) {
			if (i == j) {
				continue;
			}
			if (people[i].first < people[j].first &&
				people[i].second < people[j].second) {
				rank++;
			}
		}
		std::cout << rank << ' ';
	}
	std::cout << std::endl;
}
