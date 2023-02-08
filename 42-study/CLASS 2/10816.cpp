/**
 * @file 10816.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 숫자 카드 2
 * @date 2023-02-08
 *
 * N개의 카드를 가지고 있다.
 * 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 몇 개 가지고 있는지
 * 구해라
 *
 * 가지고 있는 숫자 카드의 수 N (1 <= N <= 500,000)
 * 숫자 카드에 적혀있는 수 (-10,000,000 <=  <= 10,000,000)
 * M (1 <= M <= 500,000)
 * M개의 정수 (-10,000,000 <=  <= 10,000,000)
 *
 * 1. 하나씩 비교하며 검색 (시간 초과)
 *
 * 2. key : value 값으로 각 숫자가 몇 개씩 있는지 센 후 Hash Map에 저장한다.
 * -> 시간 초과
 * -> 이 방법도 sync_with_stdio를 해제하면 가능하지 않을까?
 * -> 안될리가 없지.. 해결!
 *
 * 3. 정렬해서 이분탐색한다. (upper bound, lower bound 이용 -> 시간 초과..?)
 * - sync_with_stdio 해제 -> 해결!
 */
#include <iostream>
#include <unordered_map>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::unordered_map<int, int> cards;

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int cardNumber;

		std::cin >> cardNumber;
		auto found = cards.find(cardNumber);
		if (found != cards.end()) {
			found->second++;
			continue;
		}
		cards[cardNumber] = 1;
	}

	int M;
	std::cin >> M;
	for (int i = 0; i < M; i++) {
		int target;

		std::cin >> target;
		auto found = cards.find(target);
		int count = 0;
		if (found != cards.end()) {
			count = found->second;
		}
		std::cout << count << ' ';
	}
	std::cout << std::endl;
}
