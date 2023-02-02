/**
 * @file 2292.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 벌집
 * @date 2023-02-01
 *
 * 육각형으로 이루어진 벌집이 있다.
 * 중앙의 방 1부터 시작해서 이웃하는 방에 돌아가면서 1씩 증가하는 번호로 주소를
 * 매긴다. 숫자 N이 주어졌을때, 벌집의 중앙 1에서 N번 방까지 최소 개수의 방을
 * 지나서 갈 때 몇 개의 방을 지나가는지 계산해라
 *
 * 2 ~ 7 : 2
 * 8 ~ 19 : 3
 * 20 ~ 37 : 4
 * 38 ~ 61 : 5
 *
 * 6 12 18
 * 12 18 24
 * 규칙 찾는 문제
 */
#include <iostream>

int main(void) {
	int N;

	std::cin >> N;
	if (N <= 1) {
		std::cout << 1 << std::endl;
		return (0);
	}
	int start = 2;
	int end = 7;
	int rooms = 2;
	int startMultiple = 1;
	int endMultiple = 2;
	while (true) {
		if (start <= N && N <= end) {
			std::cout << rooms << std::endl;
			return (0);
		}
		start += (6 * startMultiple);
		end += (6 * endMultiple);
		startMultiple++;
		endMultiple++;
		rooms++;
	}
}
