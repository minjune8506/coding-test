/**
 * 9663 : N-Queen
 * 
 * 시간제한 : 10초
 * N-Queen 문제는 크기가 N x N인 체스판 위에 퀸 N개를 서로 공격할 수 없게
 * 놓는 문제이다.
 * N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.
 * 
 * 입력
 * 첫째 줄에 N이 주어진다. (1 <= N < 15)
 * 
 * 출력
 * 첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
 */

// 4 * 4
//   0 1 2 3
// 0 0 Q 0 0
// 1 0 0 0 Q
// 2 Q 0 0 0
// 3 0 0 Q 0

//   0 1 2 3 4
// 0 Q 0 0 0 0
// 1 0 0 Q 0 0
// 2 0 0 0 0 Q
// 3 0 Q 0 0 0
// 4 0 0 0 Q 0
// (0, 2, 4, 1, 3) -> 1차원 배열로 표현 가능 (가로 검사할 필요 없음)

#include <iostream>
#include <cstdlib>

using namespace std;

int N;
int table[15];
int answer;

void nqueen(int cnt)
{
	if (cnt >= 2)
	{
		int temp = table[cnt - 1];
		for (int i = 0 ; i < cnt - 1 ; i++)
		{
			if (table[i] == temp) // 같은 열에 있는지 검사 (세로)
				return ;
			if (abs(temp - table[i]) == abs(cnt - 1 - i)) // 대각선 방향 검사
				return ;
		}
	}
	if (cnt == N)
	{
		answer++;
		return ;
	}
	for (int i = 0 ; i < N ; i++)
	{
		table[cnt] = i;
		nqueen(cnt + 1);
	}
}

int main(void)
{
	cin >> N;

	nqueen(0);
	cout << answer << "\n";
}
