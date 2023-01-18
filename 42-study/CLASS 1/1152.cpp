/**
 * @file 1152.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 단어의 개수
 * @date 2023-01-18
 * 
 * 대소문자와 공백으로 이루어진 문자열을 입력으로 받는다.
 * 몇개의 단어가 있는지 구하라
 * 
 * 문자열의 길이는 1,000,000을 넘지 않는다.
 * 단어는 공백을 기준으로 구분한다.
 */
#include <iostream>
#include <string>
#include <sstream>

std::string &ltrim(std::string &str) {
	int i = 0;
	while (i < str.length()) {
		if (str.at(i) != ' ') {
			break;
		}
		i++;
	}
	str.erase(0, i);
	return str;
}

std::string &rtrim(std::string &str) {
	int i = str.length() - 1;
	while (i >= 0) {
		if (str.at(i) != ' ') {
			break;
		}
		i--;
	}
	str.erase(i + 1);
	return str;
}

void trim(std::string &str) {
	rtrim(ltrim(str));
}

int main(void) {
	int count = 0;
	
	std::string words;
	std::getline(std::cin, words);

	trim(words);

	std::stringstream ss(words);
	std::string token;
	while (std::getline(ss, token, ' ')) {
		count++;
	}
	std::cout << count << std::endl;
}
