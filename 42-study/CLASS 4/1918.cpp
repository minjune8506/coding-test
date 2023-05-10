/**
 * @file 1918.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 후위 표기식
 * @date 2023-05-10
 *
 * 중위 표기식 -> 후위 표기식 변환
 *
 */
#include <iostream>
#include <stack>

#define PLUS 0
#define MINUS 0
#define MULTIPLY 1
#define DIVIDE 2

void translate(std::string &exp) {
	std::stack<char> s;
	for (int i = 0; i < exp.size(); i++) {
		if (isalpha(exp[i])) {
			std::cout << exp[i];
			continue;
		} else if (exp[i] == ')') {
			while (!s.empty() && s.top() != '(') {
				std::cout << s.top();
				s.pop();
			}
			if (!s.empty() && s.top() == '(') {
				s.pop();
			}
		} else if (exp[i] == '*' || exp[i] == '/') {
			if (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				std::cout << s.top();
				s.pop();
			}
			s.push(exp[i]);
		} else if (exp[i] == '-' || exp[i] == '+') {
			if (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				std::cout << s.top();
				s.pop();
			}
			if (!s.empty() && (s.top() == '-' || s.top() == '+')) {
				std::cout << s.top();
				s.pop();
			}
			s.push(exp[i]);
		} else {
			s.push(exp[i]);
		}
	}
	while (!s.empty()) {
		if (s.top() != '(' || s.top() != ')') {
			std::cout << s.top();
		}
		s.pop();
	}
	std::cout << '\n';
}

int main(void) {
	std::string exp;

	std::cin >> exp;
	translate(exp);
}
