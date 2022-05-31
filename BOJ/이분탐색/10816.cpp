/**
 * 10816 : 숫자 카드 2
 * 
 * 숫자 카드는 정수 하나가 적혀져 있는 카드이다.
 * 상근이는 숫자 카드 N개를 가지고 있다.
 * 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개를 가지고 있는지 구하는 프로그램을 작성
 * 
 * 입력
 * 첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N (1 <= N <= 500,000)이 주어진다.
 * 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다.
 * 숫자 카드에 적혀 있는 수는 -10,000,000 보다 크거나 같고, 10,000,000보다 작거나 같다.
 * 셋째 줄에는 M(1 <= M <= 500,000)이 주어진다.
 * 넷째 줄에는 상근이가 몇 개 가지고 있는 숫자카드인지 구해야 할 M개의 정수가 공백으로 구분되어 주어진다.
 * 이 수도 -10,000,000 ~ 10,000,000이다.
 * 
 * 출력
 * 입력으로 주어진 M개의 수에 대해 각 수가 적힌 숫자 카드를 상근이가 몇 개 가지고 있는지를 공백으로 구분해 출력
 */
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int *cards;

	cards = new int[N];
	for (int i = 0 ; i < N ; i++)
		cin >> cards[i];
	
	sort(cards, cards + N);

	cin >> M;
	for (int i = 0 ; i < M ; i++)
	{
		int key;

		cin >> key;
		cout << upper_bound(cards, cards + N, key) - lower_bound(cards, cards + N, key) << " ";
	}
	cout << '\n';
	delete [] cards;
	return (0);
}
