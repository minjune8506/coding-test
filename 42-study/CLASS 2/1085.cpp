/**
 * @file 1085.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 직사각형에서 탈출
 * @date 2023-01-25
 * 
 * (x, y)에 위치해 있다.
 * 직사각형은 각 변이 좌표축에 평행하고
 * 왼쪽 아래의 꼭짓점은 (0,0) 오른쪽 위는 (w, h)에 있다.
 * 직사각형의 경계선까지 가는 거리의 최솟값을 구해라
 * 
 * - x축, y축도 고려해야 한다.
 */
#include <iostream>

int main(void) {
	int x, y, w, h;

	std::cin >> x >> y >> w >> h;
	
	int xMin = std::abs(w - x) < std::abs(x) ? std::abs(w - x) : std::abs(x);
	int yMin = std::abs(h - y) < std::abs(y) ? std::abs(h - y) : std::abs(y);
	std::cout << (xMin < yMin ? xMin : yMin) << std::endl;
}
