/**
 * @file 1436.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 영화감독 숌
 * @date 2023-01-26
 *
 * N번째 6이 연속으로 3개 이상 들어가는 수를 찾는다.
 * ex) 1666, 2666, 3666, ...
 * N은 10,000보다 작거나 같은 자연수이다.
 * 
 * - 6이 연속으로 3번이상 들어가는 제일 작은 수는 666이다.
 * - 6이 연속으로 3번이상 들어가는지 검사하는 기능
 * - 값을 증가시키면서 검사한다.
 */
#include <iostream>

bool isNumberContainsThreeSix(int number) {
	std::string str = std::to_string(number);
	if (str.find("666") != std::string::npos) {
		return true;
	}
	return false;
}

int main(void) {
	int N;

	std::cin >> N;
	for (int i = 666; N > 0; i++) {
		if (isNumberContainsThreeSix(i)) {
			N--;
			if (!N) {
				std::cout << i << std::endl;
			}
		}
	}
}
