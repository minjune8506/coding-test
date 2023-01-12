/**
 * @file 25304.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 영수증
 * @date 2023-01-12
 * 
 * 영수증의 구매한 각 물건의 가격과 개수
 * 구매한 물건들의 총 금액을 보고
 * 계산한 금액과 영수증의 총 금액이 일치하는지 검사해보자.
 */
#include <iostream>

void getInput(int &input) {
	std::cin >> input;
}

int main(void) {
	int totalPrice = 0;
	int type = 0;

	getInput(totalPrice);
	getInput(type);
	int sum = 0;
	for (int i = 0; i < type; i++) {
		int price;
		int count;
		getInput(price);
		getInput(count);
		sum += (price * count);
	}
	if (totalPrice == sum) {
		std::cout << "Yes" << std::endl;
		return 0;
	}
	std::cout << "No" << std::endl;
}
