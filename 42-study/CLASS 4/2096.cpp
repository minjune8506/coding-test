/**
 * @file 2096.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 내려가기
 * @date 2023-04-07
 *
 * N줄에 0이상 9이하의 숫자가 세 개씩 적혀있다.
 * 적혀있는 세 개의 숫자 중에서 하나를 골라서 시작한다.
 * 다음줄로 내려갈때는 바로 아래의 수로 넘어가거나
 * 바로 아래의 수와 붙어있는 수로만 이동 가능
 *
 * DP 문제?
 *
 * 1 <= N <= 100,000
 */
#include <algorithm>
#include <iostream>
#include <vector>

int N;

int main(void) {
	std::cin >> N;

	int num1, num2, num3;
	std::cin >> num1 >> num2 >> num3;

	int max[3] = {num1, num2, num3};
	int min[3] = {num1, num2, num3};

	for (int i = 1; i < N; i++) {
		int num1, num2, num3;
		std::cin >> num1 >> num2 >> num3;

		int temp1 = max[0];
		int temp2 = max[1];
		int temp3 = max[2];

		max[0] = std::max(temp1, temp2) + num1;
		max[1] = std::max(std::max(temp1, temp2), temp3) + num2;
		max[2] = std::max(temp2, temp3) + num3;

		temp1 = min[0];
		temp2 = min[1];
		temp3 = min[2];

		min[0] = std::min(temp1, temp2) + num1;
		min[1] = std::min(std::min(temp1, temp2), temp3) + num2;
		min[2] = std::min(temp2, temp3) + num3;
	}

	std::cout << *(std::max_element(max, max + 3)) << ' '
			  << *(std::min_element(min, min + 3)) << '\n';
}
