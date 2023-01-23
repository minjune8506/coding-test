/**
 * @file 2884.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 알람 시계
 * @date 2023-01-23
 * 
 * 원래 설정되어 있는 알람을 45분 앞서는 시간으로 바꾼다.
 * H 와 M 이 주어진다. (0 <= H <= 23, 0 <= M <= 59)
 * 시간은 24시간 표현을 사용한다.
 */
#include <iostream>

int main(void) {
	int H, M;
	std::cin >> H >> M;

	if (M < 45) {
		if (H < 1) {
			H += (24 - 1);
		} else {
			H -= 1;
		}
		M += (60 - 45);
	} else {
		M -= 45;
	}
	std::cout << H << ' ' << M << std::endl;
}
