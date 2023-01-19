/**
 * @file 2675.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 문자열 반복
 * @date 2023-01-20
 * 
 * 문자열 S를 입력받고, 각 문자를 R번 반복해 새 문자열 P를 만든 후 출력하는 프로그램
 * - 문자열 S를 입력받는다.
 * - 각 문자를 R번 반복해 새로운 문자열 P를 만든다.
 * - 출력한다.
 */

#include <string>
#include <iostream>
#include <sstream>

int main(void) {
	int testCaseCount;

	std::cin >> testCaseCount;

	for (int i = 0; i < testCaseCount; i++) {
		int r;
		std::string s;

		std::cin >> r >> s;
		std::stringstream p;
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < r; j++) {
				p << s.at(i);
			}
		}
		std::cout << p.str() << std::endl;
	}
}
