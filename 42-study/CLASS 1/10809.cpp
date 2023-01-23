/**
 * @file 10809.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 알파벳 찾기
 * @date 2023-01-23
 * 
 * 소문자로만 이루어진 단어 S가 주어진다.
 * 각 알파벳에 대해서 단어에 포함되어 있는 경우
 * 처음 등장하는 위치를, 포함되어 있지 않으면 -1을 출력
 */
#include <iostream>

int main(void) {
	std::string word;

	std::cin >> word;

	for (char c = 'a'; c <= 'z'; c++) {
		int found = word.find(c);
		if (found != std::string::npos) {
			std::cout << found << ' ';
			continue;
		}
		std::cout << -1 << ' ';
	}
	std::cout << std::endl;
}
