/**
 * @file 10815.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 숫자 카드
 * @date 2023-02-24
 *
 * 숫자 카드는 정수 하나가 적혀있는 카드이다.
 * 숫자 카드 N개를 가지고 있고, 정수 M개가 주어졌을 때,
 * 이 수가 적혀있는 숫자 카드를 상근이가 가지고 있는지 아닌지를 구해라
 *
 * 1 <= N <= 500,000
 * -10,000,000 <= 숫자 카드 <= 10,000,000
 * 1 <= M <= 500,000
 *
 * 검색을 많이 해야됨 -> 해쉬맵이 짱
 * 입출력이 많음 -> sync_with_stdio 처리
 */
#include <iostream>
#include <unordered_map>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::unordered_map<int, bool> cards;

	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int card;
		std::cin >> card;

		cards.insert(std::make_pair(card, true));
	}
	int M;
	std::cin >> M;
	for (int i = 0; i < M; i++) {
		int card;
		std::cin >> card;

		if (cards.find(card) != cards.end()) {
			std::cout << 1 << ' ';
			continue;
		}
		std::cout << 0 << ' ';
	}
}
