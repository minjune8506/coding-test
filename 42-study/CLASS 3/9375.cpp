/**
 * @file 9375.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 패션왕 신해빈
 * @date 2023-03-05
 *
 * 의상들이 주어졌을때 알몸이 아닌 상태로 며칠동안 밖에 있을 수 있을까..?
 * 한번 입었던 옷들의 조합을 절대 다시 입으면 안된다.
 *
 * 의상의 수 (0 <= n <= 30)
 * 의상의 이름과 종류가 공백으로 구분되어 주어진다.
 * 같은 종류의 의상은 하나만 입을 수 있다.
 *
 *
 * 경우의 수 문제
 * - 옷을 입는 경우 안입는 경우 모두 합함
 * - 종류에 따라 + 1씩 해서 (안입는경우) 모두 곱한 다음
 * - 아예 안입는 경우 -1을 하면 정답
 */
#include <iostream>
#include <map>

void solve() {
	std::map<std::string, int> clothes;

	int count;
	std::cin >> count;
	for (int i = 0; i < count; i++) {
		std::string name;
		std::string type;
		std::cin >> name >> type;

		clothes[type]++;
	}

	int answer = 1;
	for (auto it : clothes) {
		answer *= (it.second + 1);
	}
	if (answer > 0) {
		std::cout << answer - 1 << '\n';
	}
}

int main(void) {
	int t;

	std::cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}
