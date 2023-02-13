/**
 * @file 15829.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief Hashing
 * @date 2023-02-12
 *
 * 해시 함수란 임의의 길이의 입력을 받아 고정된 길이의 출력을 내보내는 함수다.
 * 입력은 영어 소문자로만 되어있다고 가정한다.
 * a는 1, b는 2, ... 영어 소문자에 번호를 부여한다.
 *
 * 항의 번호에 해당하는 만큼 특정한 숫자를 거듭게곱해서 곱해준 다음
 * 모두 더한다.
 * 그리고 나서 M으로 나눠준다.
 * r은 31 , M은 1234567891로 한다.
 */
#include <cmath>
#include <iostream>

int main(void) {
	int length;
	std::string input;
	std::cin >> length >> input;

	unsigned long long answer = 0;

	for (int i = 0; i < length; i++) {
		int alpha = input.at(i) - 'a' + 1;
		long long pow = 1;
		for (int j = 0; j < i; j++) {
			pow *= 31;
			if (pow > 1234567891) {
				pow %= 1234567891;
			}
		}
		answer += (alpha * pow % 1234567891);
		if (answer > 1234567891) {
			answer %= 1234567891;
		}
	}
	std::cout << answer << std::endl;
}
