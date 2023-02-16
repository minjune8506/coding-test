/**
 * @file 1107.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 리모컨
 * @date 2023-02-15
 *
 * 리모컨에는 버튼이 0 ~ 9, +, -가 있다.
 *
 * +를 누르면 현재 보고 있는 채널에서 +1된 채널로 이동한다.
 * -를 누르면 -1된 채널로 이동한다.
 *
 * 채널 0에서 -를 누른 경우는 채널이 변하지 않고, 채널은 무한대까지 있다.
 *
 * 이동하려고 하는 채널은 N이고, 어떤 버튼이 고장났는지 주어졌을 때,
 * 채널 N으로 이동하기 위해 버튼을 최소 몇 번 눌러야 하는지 구해라
 *
 * 지금 보고 있는 채널은 100번이다.
 *
 * N (0 <= N <= 500,000)
 * 고장난 숫자 버튼의 개수 M (0 <= M <= 10)
 *
 * - 고장난 숫자를 제외하고 N에 최대한 가깝게 만들 수 있는 숫자를 찾는다.
 * - +, -를 몇번 눌러야 N이 되는지 구한다.
 * - 버튼을 누른 횟수를 출력한다.
 */
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

bool checkNumber(std::vector<int> numbers, int number) {
	std::string str = std::to_string(number);
	for (auto c : str) {
		if (std::find(numbers.begin(), numbers.end(), c - '0') ==
			numbers.end()) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int N, M;

	std::cin >> N >> M;
	std::vector<int> numbers;

	for (int i = 0; i <= 9; i++) {
		numbers.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		int number;

		std::cin >> number;
		numbers.erase(std::find(numbers.begin(), numbers.end(), number));
	}
	int min = std::abs(100 - N);
	for (int i = 0; i < 1000000; i++) {
		if (checkNumber(numbers, i)) {
			int length = std::to_string(i).length();
			if (length + std::abs(i - N) < min) {
				min = length + std::abs(i - N);
			}
		}
	}
	std::cout << min << std::endl;
}
