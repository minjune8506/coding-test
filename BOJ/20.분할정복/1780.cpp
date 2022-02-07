/*
 * 1780 : 종이의 개수
 *
 * N * N 크기의 행렬로 표현되는 종이가 있다.
 * 각 칸에는 -1, 0, 1 중 하나가 저장되어 있다.
 * 규칙에 따라 적절한 크기로 자른다.
 * 1. 만약 종이가 모두 같은 수로 되어있다면 이 종이를 그대로 사용한다.
 * 2. (1)이 아닌 경우에는 종이를 같은 크기의 종이 9개로 자르고, 각각의 잘린 종이에 대해 (1)을 반복
 * 
 * 입력 :
 * N (1 <= N <= 3^7 N은 3의 k승이다.)
 * N개의 줄에 N개의 정수로 행렬이 주어진다.
 * 
 * 출력 :
 * -1로 채워진 종이의 개수
 * 0으로 채워진 종이의 개수
 * 1로 채워진 종이의 개수
*/

// 풀이
// N*N개의 입력을 받아 2차원 배열에 채운다.
// x ~ x + n , y ~ y + n으로 구간을 나누어 0, 1, -1 로만 채워져 있는지 검사한다.
#include <iostream>


using namespace std;

int n;
int **paper;
int minus_one;
int zero;
int plus_one;

void check_paper(int x, int y, int n)
{
	int number;
	int flag;

	number = paper[y][x];
	flag = 0;

	for (int i = y ; i < y + n ; i++)
	{
		for (int j = x ; j < x + n ; j++)
		{
			if (paper[i][j] != number)
				flag = 1;
		}
		if (flag)
			break ;
	}
	if (flag) // -1, 0, 1로만 채워지지 않은 경우
	{
		check_paper(x, y, n / 3);
		check_paper(x + n / 3, y, n / 3);
		check_paper(x + n / 3 * 2, y, n / 3);
		check_paper(x, y + n / 3, n / 3);
		check_paper(x + n / 3, y + n / 3, n / 3);
		check_paper(x + n / 3 * 2, y + n / 3, n / 3);
		check_paper(x, y + n / 3 * 2, n / 3);
		check_paper(x + n / 3, y + n / 3 * 2, n / 3);
		check_paper(x + n / 3 * 2, y + n / 3 * 2, n / 3);
	}
	else
	{
		if (number == -1)
			minus_one++;
		else if (number == 0)
			zero++;
		else
			plus_one++;
	}
}

int main(void)
{
	cin >> n;

	// memory allocation
	paper = new int*[n];
	for (int i = 0 ; i < n ; i++)
		paper[i] = new int[n];
	
	// input
	for (int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < n ; j++)
			cin >> paper[i][j];

	// solve
	check_paper(0, 0, n);

	// output
	cout << minus_one << "\n" << ::zero << "\n" << plus_one << "\n";
}
