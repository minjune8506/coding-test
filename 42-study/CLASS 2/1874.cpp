/**
 * @file 1874.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 스택 수열
 * @date 2023-01-29
 *
 * 1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓으면 수열을 만들 수 있다.
 * 스택에 push하는 순서는 반드시 오름차순을 지킨다.
 * 임의의 수열이 주어졌을 때 스택을 이용해 수열을 만들 수 있는지
 * 어떤 순서로 push pop을 해야하는지 알아내라
 *
 * - N개의 숫자를 입력받는다.
 * - 작은 수부터 스택에 넣으면서 만들어야 하는 수열과 비교한다.
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

std::vector<char> solve(std::stack<int> &s, std::vector<int> &origin,
						std::vector<int> &sorted) {
	std::vector<char> stackOperators;
	int numberIdx = 0;
	int originIdx = 0;

	while (originIdx < origin.size()) {
		if (!s.empty() && s.top() == origin[originIdx]) {
			s.pop();
			stackOperators.push_back('-');
			originIdx++;
			continue;
		}
		if (numberIdx >= sorted.size()) {
			break;
		}
		s.push(sorted[numberIdx]);
		stackOperators.push_back('+');
		numberIdx++;
	}
	return stackOperators;
}

int main(void) {
	int N;

	std::cin >> N;
	std::stack<int> s;
	std::vector<int> origin;  // 원본
	std::vector<int> sorted;  // 정렬

	for (int i = 0; i < N; i++) {
		int number;

		std::cin >> number;
		origin.push_back(number);
	}

	sorted = origin;
	std::sort(sorted.begin(), sorted.end());

	std::vector<char> stackOperators = solve(s, origin, sorted);
	if (!s.empty()) {
		std::cout << "NO" << std::endl;
		return (0);
	}
	for (auto stackOperator : stackOperators) {
		std::cout << stackOperator << '\n';
	}
	std::cout << std::endl;
}
