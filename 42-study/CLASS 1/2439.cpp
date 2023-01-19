/**
 * @file 2439.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 별 찍기 -2
 * @date 2023-01-19
 * 
 *     *
 *    **
 *   ***
 *  ****
 * ***** (1 <= N <= 100)
 */
#include <iostream>
#include <iomanip>
#include <sstream>

int main(void) {
	int N;
	std::cin >> N;
	
	for (int i = 1; i <= N; i++) {
		std::stringstream ss;
		for (int j = 0; j < i; j++) {
			ss << "*";
		}
		std::cout << std::setw(N) << ss.str() << std::endl;
	}
}
