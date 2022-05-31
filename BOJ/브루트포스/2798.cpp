/**
 * 2798 : 블랙잭
 * 
 * 블랙잭의 규칙은 카드의 합이 21을 넘지 않는 한도 내에서 카드의 합을
 * 최대한 크게 만드는 게임이다.
 * 각 카드에는 양의 정수가 쓰여 있다. 그 다음, 딜러는 N장의 카드를 모두
 * 숫자가 보이도록 바닥에 놓는다. 그런 후에 딜러는 숫자 M을 외친다.
 * 플레이어는 제한된 시간 안에 N장의 카드 중에서 3장을 골라야 한다.
 * 플레이어가 고른 카드의 합은 M을 넘지 않으면서 M과 최대한 가깝게 만들어야 한다.
 * N장의 카드에 써져 있는 숫자가 주어졌을때, M을 넘지 않으면서 M에 최대한 가까운 카드 3장의
 * 합을 구해 출력하라
 * 
 * 입력
 * 
 * 카드의 개수 N (3 <= N <= 100) 과 M (10 <= M <= 300,000)
 * 카드에 쓰여있는 수가 주어지며, 100,000을 넘지않는 양의 정수이다.
 * 합이 M을 넘지 않는 카드 3장을 찾을 수 있는 경우만 입력으로 주어진다.
 * 
 * 출력
 * 
 * M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 출력
 */
#include <iostream>

int n, m;

int main(void)
{
	int *cards;
	int *selected;
	int max = 0;
	int temp = 0;

	// input
	std::cin >> n >> m;
	cards = new int[n];
	for (int i = 0 ; i < n ; i++)
		std::cin >> cards[i];
	selected = new int[m];
	
	// solve
	for (int i = 0 ; i < n - 2 ; i++)
	{
		selected[0] = cards[i];
		for (int j = i + 1 ; j < n - 1 ; j++)
		{
			selected[1] = cards[j];
			for (int k = j + 1 ; k < n ; k++)
			{
				selected[2] = cards[k];
				temp = selected[0] + selected[1] + selected[2];
				if (temp <= m && temp > max)
					max = temp;
			}
		}
	}
	
	// output
	std::cout << max << "\n";

	delete [] cards;
	delete [] selected;
}
