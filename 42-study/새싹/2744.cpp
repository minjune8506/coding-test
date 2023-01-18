/**
 * @file 2744.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 대소문자 바꾸기
 * @date 2023-01-17
 * 
 * 소문자와 대문자로 이루어진 단어가 주어진다.
 * 대문자 -> 소문자 / 소문자 -> 대문자로 바꾸어 출력
 * 
 * 단어의 길이는 최대 100이다.
 */
#include <iostream>
#include <string>

int main(void){
	std::string word;
	std::cin >> word;
	
	std::string answer = "";
	for (int i = 0; i < word.length(); i++) {
		if (isupper(word.at(i))) {
			answer += tolower(word.at(i));
			continue;
		}
		answer += toupper(word.at(i));
	}
	std::cout << answer << std::endl;
}
