/**
 * @file 11718.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 그대로 출력하기
 * @date 2023-01-17
 * 
 * 입력 받은 대로 출력하는 프로그램
 * 
 * point
 * - 여러 줄에 들어오는 입력을 어떻게 처리할 것인지? (std::getline)
 * - 마지막을 어떻게 구분할지? (EOF)
 */
#include <iostream>
#include <string>

int main(void) {
	while (true) {
		std::string input;
		
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		std::cout << input << std::endl;
	}

}
