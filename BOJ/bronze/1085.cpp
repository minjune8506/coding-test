/**
 * 1085 : 직사각형에서 탈출
 * 
 * 한수는 지금 (x, y)에 있다.
 * 직사각형은 각 변이 좌표축에 평행하고, 왼쪽 아래 꼭짓점은 (0,0)
 * 오른쪽 위 꼭짓점은 (w,h)에 있다.
 * 직사각형의 경게선까지 가능 거리의 최솟값을 구하는 프로그램을 작성
 * 
 * 입력
 * x, y, w, h가 주어진다.
 * (1 <= w, h <= 1,000)
 * (1 <= x <= w - 1)
 * (1 <= y <= h - 1)
 * (x, y, w, h는 정수)
 * 
 * 출력
 * 정답을 출력한다.
 */
#include <iostream>
#include <algorithm>

using namespace std;

int x, y, w, h;

int main(void)
{
	cin >> x >> y >> w >> h;
	int tmp = min(h - y, w - x);
	int tmp2 = min(x, y);
	cout << min(tmp, tmp2) << '\n';
}
