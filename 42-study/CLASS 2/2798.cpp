/**
 * @file 2798.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 블랙잭
 * @date 2023-02-04
 *
 * N장의 카드 중에서 3장의 카드를 가져와 M을 넘지 않고 M과 최대한 가깝게
 * 만들어야 한다.
 * N장의 카드에 써져 있는 숫자가 주어졌을 때, M을 넘지 않으면서
 * M에 최대한 가까운 카드 3장의 합을 구해 출력해라
 *
 * 3 <= N <= 100
 * 10 <= M <= 300,000
 * 각 카드의 숫자는 100,000을 넘지 않는 양의 정수이다.
 *
 * - 중복되지 않는 3장의 카드를 고른다.
 * - M보다 큰 값은 버린다.
 * - 3장을 고를 수 있는 모든 경우의 수를 고려한다.
 * - 오름차순으로 정렬하여 마지막에 있는 수를 출력한다.
 */
#include <algorithm>
#include <iostream>
#include <vector>

void solve(std::vector<int> &cards, int target) {
	std::vector<int> totals;

	for (int i = 0; i < cards.size(); i++) {
		for (int j = i + 1; j < cards.size(); j++) {
			for (int k = j + 1; k < cards.size(); k++) {
				int sum = cards[i] + cards[j] + cards[k];
				if (sum <= target) {
					totals.push_back(sum);
				}
			}
		}
	}
	std::sort(totals.begin(), totals.end());
	std::cout << *(totals.end() - 1) << std::endl;
}

int main(void) {
	int cardCount, target;
	std::vector<int> cards;

	std::cin >> cardCount >> target;
	for (int i = 0; i < cardCount; i++) {
		int card;

		std::cin >> card;
		cards.push_back(card);
	}
	solve(cards, target);
}
