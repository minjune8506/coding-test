/**
 * @file 1181.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 단어 정렬
 * @date 2023-01-25
 *
 * 알파벳 소문자로 이루어진 N개의 단어를
 * 1. 길이가 짧은 순
 * 2. 길이가 같으면 사전 순
 * 으로 정렬해라
 *
 * 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.
 * 
 * - c++11 : lambda
 * - sort
 * - decltype
 */
#include <algorithm>
#include <iostream>
#include <set>

int main(void) {
	auto cmp =
		[](std::string first, std::string second) {
			if (first.length() == second.length()) {
				return first < second;
			}
			return first.length() < second.length();
		};
	std::set<std::string, decltype(cmp)> words(cmp);
	int wordCount;

	std::cin >> wordCount;
	for (int i = 0; i < wordCount; i++) {
		std::string word;

		std::cin >> word;
		words.insert(word);
	}

	for (auto word : words) {
		std::cout << word << '\n';
	}
	std::cout << std::endl;
}
