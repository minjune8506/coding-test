/**
 * @file 1541.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 잃어버린 괄호
 * @date 2023-02-17
 *
 * 양수, +, -, 괄호로 식을 만들고, 괄호를 모두 지웠다.
 * 괄호를 적절히 넣어서 식의 값을 최소로 만드려고 한다.
 *
 * 식은 0 ~ 9, +, -로만 이루어져 있고, 가장 처음과 마지막은 숫자이다.
 * 연속해서 두 개 이상의 연산자가 나타나지 않고,
 * 5자리보다 많이 연속되는 숫자는 없다. (숫자의 최대는 99999)
 * 수는 0으로 시작할 수 있다.
 * 식의 길이는 50보다 작거나 같다.
 *
 * e.g. 55-50+40 => -35
 *
 * - 마이너스가 나오면 뒤에 +가 나와도 -로취급하고 문제를 해결한다.
 * - 어려웠음..
 */
#include <iostream>
#include <string>

int main(void) {
	std::string expression;

	std::cin >> expression;
	bool isMinus = false;
	int result = 0;
	std::string number = "";
	for (int i = 0; i <= expression.size(); i++) {
		if (i == expression.size() || expression[i] == '+' ||
			expression[i] == '-') {
			result = isMinus ? result - std::stoi(number)
							 : result + std::stoi(number);
			number = "";
		} else {
			number += expression[i];
		}

		if (expression[i] == '-') {
			isMinus = true;
		}
	}
	std::cout << result << std::endl;
}
