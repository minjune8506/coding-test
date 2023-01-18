/**
 * @file 9086.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 문자열
 * @date 2023-01-17
 * 
 * 문자열이 입력으로 들어오면 첫 글자와 마지막 글자를 출력
 * 
 * 테스트 케이스의 개수 T(1 <= T <= 10)
 * 각 테스트 케이스는 한 줄에 하나의 문자열이 주어진다.
 * 공백은 없고, 문자열의 길이는 100보다 작다.
 */

#include <string>
#include <iostream>

int main(void) {
	int testCase;

	std::cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		std::string word;
		std::cin >> word;

		std::cout << *word.begin() << *(word.end() - 1) << std::endl;
	}
}
