/**
 * 2480 : 주사위 세개
 * 
 * 1 ~ 6까지의 눈을 가진 3개의 주사위를 던져서 다음과 같은 규칙에 따라 상금을 받는 게임이 있다.
 * 1. 같은 눈이 3개가 나오면 10,000원 + (같은 눈) x 1000원의 상금을 받는다.
 * 2. 같은 눈이 2개가 나오는 경우 1,000원 + (같은 눈) x 100원의 상금을 받는다.
 * 3. 모두 다른 눈이 나오는 경우에는 (가장 큰 눈) x 100원의 상금을 받는다.
 * 3개 주사위의 나온 눈이 주어질 때, 상금을 계산하는 프로그램을 작성
 * 
 * 입력
 * 첫쨰 줄에 3개의 눈이 빈칸을 사이에 두고 각각 주어진다.
 * 
 * 출력
 * 첫쨰 줄에 게임의 상금을 출력
 */

#include <iostream>

using namespace std;

int main(void)
{
	int prizeMoney;
	int a, b, c;

	cin >> a >> b >> c;
	if (a == b)
	{
		if (b == c)
			prizeMoney = 10000 + a * 1000;
		else
			prizeMoney = 1000 + a * 100;
	}
	else if (a == c || b == c)
		prizeMoney = 1000 + c * 100;
	else
	{
		int big = max(a, b);
		if (big < c)
			prizeMoney = c * 100;
		else
			prizeMoney = big * 100;			
	}
	cout << prizeMoney << "\n";
}
