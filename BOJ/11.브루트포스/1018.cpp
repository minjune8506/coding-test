/**
 * 1018 : 체스판 다시 칠하기
 *
 * 시간제한 : 2초
 * MN개의 단위 정사각형으로 나누어져 있는 MxN 크기의 보드를 찾았다.
 * 어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다.
 * 지민이는 이 보드를 잘라서 8x8 크기의 체스판으로 만드려고 한다.
 *
 * 체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다.
 * 각 칸이 검은색과 흰색 중 하나로 칠해져 있고, 변을 공유하는 두 개의 사각형은
 * 다른 색으로 칠해져 있어야 한다. 맨 왼쪽 위 칸이 흰색인 경우, 검은색인 경우로 나뉜다.
 *
 * 보드가 체스판처럼 칠해져 있다는 보장이 없어서 지민이는 8x8 크기의 체스판으로 잘라낸 후에
 * 몇 개의 정사각형을 다시 칠해야겠다고 생각했다.
 * 당연히 8*8 크기는 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오
 *
 * 입력
 * N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다.
 * 둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다.
 * B는 검은색, W는 흰색이다.
 *
 * 출력
 * 첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.
 */
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

char board1[8][8] = {
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}};

char board2[8][8] = {
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}};

char map[51][51];

int WB_cnt(int x, int y)
{
	int cnt = 0;
	for (int i = 0 ; i < 8 ; i++)
		for (int j = 0 ; j < 8 ; j++)
			if (map[x + i][y + j] != board1[i][j])
				cnt++;
	return (cnt);
}

int BW_cnt(int x, int y)
{
	int cnt = 0;
	for (int i = 0 ; i < 8 ; i++)
		for (int j = 0 ; j < 8 ; j++)
			if (map[x + i][y + j] != board2[i][j])
				cnt++;
	return (cnt);
}

int main(void)
{
	int min_value = INT32_MAX;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			int temp = min(WB_cnt(i, j), BW_cnt(i, j));
			if (min_value > temp)
				min_value = temp;
		}
	}
	cout << min_value << "\n";
}
