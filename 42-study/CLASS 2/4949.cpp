/**
 * @file 4949.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 균형잡힌 세상
 * @date 2023-02-06
 *
 * 문자열에 포함되는 괄호는 소괄호와 대괄호 2종류이고, 문자열이 균형을
 * 이루는 조건은 다음과 같다.
 *
 * - 모든 왼쪽 소괄호( 는 오른쪽 소괄호)와 짝을 이뤄야 한다.
 * - 모든 왼쪽 대괄호[ 는 오른쪽 대괄호]와 짝을 이뤄야 한다.
 * - 모든 오른쪽 괄호는 자신과 짝을 이루는 왼쪽 괄호가 존재한다.
 * - 모든 괄호들의 짝은 1:1 매칭만 가능하다.
 * - 짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다.
 *
 * 반례
 * - [[만 들어왔을 경우
 */
#include <iostream>
#include <stack>
#include <string>

int main(void) {
	std::string str;

	while (true) {
		std::stack<int> s;
		std::getline(std::cin, str);
		if (str == ".") {
			break;
		}
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '[')
				s.push(str[i]);
			else if (str[i] == ')' || str[i] == ']') {
				if (s.empty()) {
					std::cout << "no" << std::endl;
					break;
				} else if (str[i] == ')' && s.top() != '(') {
					std::cout << "no" << std::endl;
					break;
				} else if (str[i] == ']' && s.top() != '[') {
					std::cout << "no" << std::endl;
					break;
				}
				s.pop();
			}
			if (i + 1 == str.length()) {
				if (s.empty())
					std::cout << "yes" << std::endl;
				else
					std::cout << "no" << std::endl;
			}
		}
	}
}
