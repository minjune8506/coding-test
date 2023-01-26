/**
 * @file 1259.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 팰린드롬수
 * @date 2023-01-25
 * 
 * 어떤 단어를 뒤에서부터 읽어도 똑같다면 팰린드롬 ex) 우영우
 * 무의미한 0은 앞에 붙지 않는다.
 * 팰린드롬수면 yes / no를 출력해라
 * 
 * 입력의 마지막줄에는 0이 주어진다.
 */
#include <iostream>

int main(void) {
	while (true) {
		std::string number;

		std::cin >> number;
		if (number == "0") {
			break;
		}
		bool flag = false;
		for (int i = 0; i < number.length() / 2; i++) {
			if (number.at(i) != number.at(number.length() - 1 - i)) {
				flag = true;
				break;
			}
		}
		if (flag) {
			std::cout << "no" << std::endl;
			continue;
		}
		std::cout << "yes" << std::endl;
	}
}
