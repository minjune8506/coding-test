/**
 * @file 2743.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 단어 길이 재기
 * @date 2023-01-17
 * 
 * 알파벳으로만 이루어진 단어를 입력으로 받아
 * 길이를 출력하는 프로그램
 * 
 * 영어 소문자, 대문자 이외의 입력은 주어지지 않음
 * 단어의 길이는 최대 100
 */
#include <iostream>

int main(void) {
	std::string word;
	std::cin >> word;

	std::cout << word.length() << std::endl;
}
