/*
2869 : 달팽이는 올라가고 싶다
** 달팽이가 높이가 V미터인 나무 막대를 올라간다.
** 낮에 A미터 올라갈 수 있고, 잠을 자는 동안 B미터 미끄러진다.
** 정상에 올라가면 미끄러지지 않는다. 나무 막대를 모두 올라가려면 며칠이 걸리는가?
** 입력 : A, B, V 가 공백으로 구분되어 주어진다.
** (1 <= B < A <= V <= 1,000,000,000)
*/
/*
** Key Point
** 1. 달팽이가 올라가야 하는 거리는?
**	-> V-A 거리까지 가면 다음날에 A만큼 올라가므로 미끄러지지 않는다.
** 2. V-A 까지 가는 시간을 단축하려면?
**	-> 반복문이 아닌 곱셈, 나눗셈으로 해결.
*/
#include <iostream>

using namespace std;

int	main(void)
{
	int A, B, V;
	int move = 0;
	int days = 0;
	int tmp = 0;

	cin >> A >> B >> V;
	tmp = (V - A) / (A - B);
	move += (tmp * (A - B));
	days += tmp;
	while (move < V)
	{
		move += A;
		if (move >= V)
		{
			days++;
			break ;
		}
		move -= B;
		days++;
	}
	cout << days << "\n";
}
