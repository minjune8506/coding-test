/**
 * @file 9012.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 괄호
 * @date 2023-02-07
 *
 * 괄호 문자열은 두 개의 괄호인 ( )으로 구성되어 있는 문자열이다.
 * 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열이라고 한다.
 * 입력으로 주어진 괄호 문자열이 올바른 괄호 문자열인지 판단해서
 * YES / NO로 나타내라.
 *
 * - Stack 이용
 */
#include <iostream>
#include <stack>

bool checkParenthesis(std::string &line) {
	std::stack<int> s;

	for (int i = 0; i < line.length(); i++) {
		char c = line.at(i);
		if (c == '(') {
			s.push(c);
		} else if (c == ')') {
			if (s.empty() || s.top() != '(') {
				return false;
			}
			s.pop();
		}
	}
	if (s.empty()) {
		return true;
	}
	return false;
}

int main(void) {
	int testCaseCount;

	std::cin >> testCaseCount;
	for (int i = 0; i < testCaseCount; i++) {
		std::string parenthesisLine;

		std::cin >> parenthesisLine;
		if (checkParenthesis(parenthesisLine)) {
			std::cout << "YES" << std::endl;
			continue;
		}
		std::cout << "NO" << std::endl;
	}
}
