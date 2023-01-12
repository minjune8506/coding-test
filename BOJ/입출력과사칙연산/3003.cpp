/**
 * @file 3003.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 킹, 퀸, 룩, 비숍, 나이트, 폰
 * @date 2023-01-12
 *
 * 킹 1개, 퀸 1개, 룩 2개, 비숍 2개, 나이트 2개, 폰 8개로 구성
 * 흰색 피스의 개수가 주어졌을때, 올바는 세트가 되려면 몇개를 더하거나
 * 빼야하는지 구하라
 */
#include <iostream>
#include <vector>

int original[6] = {1, 1, 2, 2, 2, 8};

void getInput(std::vector<int> &chess) {
	for (int i = 0; i < 6; i++) {
		int num;
		std::cin >> num;
		chess.push_back(num);
	}
}

void printResult(std::vector<int> &chess) {
	for (int i = 0; i < 6 ;i++) {
		std::cout << original[i] - chess[i];
		if (i != 5) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

int main(void) {
	std::vector<int> chess;
	getInput(chess);
	printResult(chess);
}
