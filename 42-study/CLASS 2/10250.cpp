/**
 * @file 10250.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief ACM 호텔
 * @date 2023-02-07
 *
 * 손님은 호텔 정문으로부터 걸어서 가장 짧은 거리에 있는 방을 선호한다.
 * 호텔 정문으로부터 걷는 거리가 가장 짧도록 방을 배정하는 프로그램
 *
 * 호텔은 직사각형 모양이다.
 * 각 층에 W개의 방이 있는 H층 건물이다. (1 <= H, W <= 99)
 * 엘리베이터는 가장 왼쪽에 있다.
 *
 * 방번호는 YXX나 YYXX 형태이다. Y / YY는 층 수를 X / XX 는 엘리베이터로부터
 * 거리를 나타낸다.
 *
 * 초기에 모든 방이 비어있다고 가정하고 N 번째로 도착한
 * 손님에게 배정될 방 번호를 계산해라
 *
 * 층 수는 order % height로 결정한다. 0일 경우 height로 지정
 * 방 번호는 order / height로 결정한다. 나머지가 있을 경우 + 1
 */
#include <iomanip>
#include <iostream>

void assignRoom(int height, int width, int order) {
	int floor = order % height ? order % height : height;
	int roomNumber = order / height;
	if (order % height) {
		roomNumber += 1;
	}
	std::cout << std::to_string(floor) << std::setw(2) << std::setfill('0')
			  << std::to_string(roomNumber) << std::endl;
}

int main(void) {
	int testCaseCount;

	std::cin >> testCaseCount;
	for (int i = 0; i < testCaseCount; i++) {
		int h, w, n;

		std::cin >> h >> w >> n;
		assignRoom(h, w, n);
	}
}
