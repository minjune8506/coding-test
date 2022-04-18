/**
 * 1100 : 하얀 칸
 * 
 * 체스판의 크기는 8 * 8이고 검정칸과 하얀칸이 번갈아가면서 색칠되어 있다.
 * 가장 왼쪽 위칸(0,0)은 하얀색이다.
 * 체스판의 상태가 주어졌을 때, 하얀 칸 위에 말이 몇개 있는지 출력
 * 
 * 입력
 * 체스판의 상태가 주어진다. '.' : 빈칸 'F' : 말이 있는 칸
 * 
 * 출력
 * 문제의 정답 출력
 * 
 * 풀이
 * 왼쪽 맨 위의 칸이 주어졌으니
 * 짝수 줄 : 0, 2, 4, ... (짝수)
 * 홀수 줄 : 1, 3, 5, ... (홀수) 에
 * 말이 놓여있는지 확인하고 count를 증가시킨다.
 */
#include <iostream>

using namespace std;

int main(void)
{
	char table[8][8];
	int count = 0;

	for (int i = 0 ; i < 8 ; i++)
	{
		for (int j = 0 ; j < 8 ; j++)
		{
			cin >> table[i][j];
			if (i % 2 == 0 && j % 2 == 0)
			{
				if (table[i][j] == 'F')
					count++;
			}
			if (i % 2 == 1 && j % 2 == 1)
			{
				if (table[i][j] == 'F')
					count++;
			}
		}
	}
	cout << count << '\n';
}
