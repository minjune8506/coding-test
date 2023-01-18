/**
 * @file 5597.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 과제 안 내신 분..?
 * @date 2023-01-17
 * 
 * 학생이 30명 있는데, 각 학생별로 1 ~ 30번까지의 번호가 있다.
 * 28명의 학생이 과제 제출 / 제출 안 한 학생 2명의 번호를 구하는 프로그램
 * 
 * 입력은 28줄, 제출자의 출석번호가 주어진다.
 * 출석번호의 중복은 없다
 */
#include <iostream>

int main(void) {
	bool students[31] = {};

	for (int i = 0; i < 28; i++) {
		int studentId;

		std::cin >> studentId;
		students[studentId] = true;
	}

	for (int i = 1; i <= 30; i++) {
		if (students[i] != true) {
			std::cout << i << std::endl;
		}
	}
}
