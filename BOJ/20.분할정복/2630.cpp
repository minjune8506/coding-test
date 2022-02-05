/* 2630 : 색종이 만들기
 *
 * N * N 크기의 종이가 있다. (N = 2^k 1 <= k <= 7)
 * 전체 종이가 같은 색으로 칠해져 있지 않으면 가로와 세로의 중간부분을 잘라서 4개의 N/2 * N/2 종이로 나눈다.
 * 나눈 종이도 같은 색으로 칠해져 있지 않으면 다시 나눈다.
 * 나눠진 종이가 모두 하얀색 / 파란색으로 칠해져 있거나 하나의 정사각형 칸이 되어 더이상 자를 수 없을 때까지 반복
 * 
 * 입력 
 * 첫쨰줄 : N
 * 둘째줄 ~ : 각 가로줄의 정사각형칸들의 색이 윗줄부터 차례로 주어진다.
 * 하얀색 : 0 파란색 : 1 각숫자 사이에는 빈칸이 하나씩 있다.
 * 
 * 출력
 * 하얀색 색종이의 개수
 * 파란색 색종이의 개수
*/

/*
 * 풀이
 * 
 * 모두 같은 색으로 칠해져 있을 때까지 반으로 계속 나눈다.
 * 나눈 종이의 왼쪽 상단의 시작점을 x, y로 나타내고
 * 길이는 n으로 표시한다.
*/

#include <iostream>

using namespace std;

int n;
int **map;
int white, blue;

void solve(int x, int y, int n)
{
	int color;
	int flag;

	color = map[y][x];
	flag = 0;
	for (int i = y ; i < y + n ; i++)
	{
		for (int j = x ; j < x + n ; j++)
		{
			if (map[i][j] != color)
				flag = 1;
		}
		if (flag)
			break ;
	}
	if (!flag)
	{
		if (color)
			blue++;
		else
			white++;
	}
	else
	{
		solve(x, y, n / 2);
		solve(x + n / 2, y, n / 2);
		solve(x, y + n / 2, n / 2);
		solve(x + n / 2, y + n / 2, n / 2);
	}
}

int main(void)
{
	cin >> n;

	// memory allocation
	map = (int **)malloc(sizeof(int *) * n);
	for (int i = 0 ; i < n ; i++)
		map[i] = (int *)malloc(sizeof(int) * n);
	
	// input 
	for (int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < n ; j++)
			cin >> map[i][j];
	
	// solve
	solve(0, 0, n);

	// output
	cout << white << "\n" << blue << "\n";

	for (int i = 0 ; i < n ; i++)
		delete [] map[i];
	delete[] map;
}
