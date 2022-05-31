/**
 * 2164 : 카드2
 * 
 * N장의 카드가 있다. 각각의 카드는 차례로 1부터 N까지의 번호가 붙어 있고
 * 1번 카드가 제일 위에, N번 카드는 제일 아래에 순서대로 놓여있다.
 * 
 * 카드가 한 장 남을 때까지 다음 동작을 반복하게 된다.
 * 1. 제일 위에 있는 카드를 바닥에 버린다.
 * 2. 제일 위에 있는 카드를 아래에 있는 카드 밑으로 옮긴다.
 * N이 주어졌을 때, 제일 마지막에 남게 되는 카드를 구하는 프로그램을 작성하시오.
 * 
 * 입력
 * 첫째 줄에 정수 N(1 <= N <= 500,000)이 주어진다.
 * 
 * 출력
 * 첫쨰 줄에 남게 되는 카드의 번호를 출력
 */
// 1 2 3 4 5 6
// 3 4 5 6 2
// 5 6 2 4
// 2 4 6
// 6 4
// 4
#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	queue<int> que;
	int last;
	int N;

	cin >> N;
	for (int i = 0 ; i < N ; i++)
		que.push(i + 1);
	while (que.size() != 1)
	{
		que.pop();
		if (que.size())
		{
			last = que.front();
			que.pop();
			que.push(last);
		}
	}
	cout << que.front() << "\n";
}
