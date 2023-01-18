/**
 * @file 1157.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 단어 공부
 * @date 2023-01-18
 * 
 * 알파벳 대소문자로 된 단어가 주어진다.
 * 단어에서 가장 많이 사용된 알파벳이 무엇인지 구하는 프로그램
 * 대소문자를 구분하지 않는다.
 * 
 * 단어의 길이는 1,000,000을 넘지 않는다.
 * 
 * 가장 많이 사용된 알파벳이 여러 개면 ?를 출력한다.
 * 
 * 1. 단어를 입력받는다.
 * 2. 모두 소문자로 변환한다.
 * 3. 알파벳 개수만큼 배열을 생성
 * 4. 알파벳 - 'a'로 인덱스를 구하고 개수를 센다.
 * 5. 가장 많이 사용된 알파벳의 인덱스를 구한다.
 * 6. 가장 많이 사용된 알파벳이 한개인지, 여러개인지 구한다.
 * 7. 출력
 */
#include <iostream>
#include <algorithm>

const int ALPHABET = 26;

int alpha[ALPHABET];

int main(void) {
	std::string word;
	std::cin >> word;

	for (auto &it : word) {
		it = tolower(it);
		alpha[it - 'a']++;
	}

	int max = 0;
	for (int i = 0; i < ALPHABET; i++) {
		if (alpha[i] > alpha[max]) {
			max = i;
		}
	}

	for (int i = 0; i < ALPHABET; i++) {
		if (i != max && alpha[i] == alpha[max]) {
			std::cout << "?" << std::endl;
			return 0;
		}
	}
	std::cout << (char)('A' + max) << std::endl;
}
