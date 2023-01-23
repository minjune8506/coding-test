/**
 * @file 8958.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief OX퀴즈
 * @date 2023-01-23
 *
 * OOXXOXXOOO의 점수는
 * 1 + 2 + 0 + 0 + 1 + 0 + 0 + 1 + 2 + 3 = 10점이다.
 * 연속된 O의 점수는 1씩 증가한다.
 *
 * 점수를 구하는 프로그램을 작성하시오.
 */
#include <iostream>
#include <vector>

int main(void) {
	int testCase;
	std::cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		std::string result;
		std::cin >> result;

		std::vector<int> counts;
		int sum = 0;
		for (int i = 0; i < result.length(); i++) {
			result.at(i) == 'O' ? counts.push_back(1) : counts.push_back(0);
			if (i > 0 && counts[i] > 0 && counts[i - 1] > 0) {
				counts[i] += counts[i - 1];
			}
			sum += counts[i];
		}
		std::cout << sum << std::endl;
	}
}
