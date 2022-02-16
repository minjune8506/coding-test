/**
 * 3933 : 라그랑주의 네 제곱수 정리
 * 
 * 시간제한 : 2초
 * 양의 정수는 최대 4개의 제곱수로 표현할 수 있다. 이 이론을 라그랑주의 네 제곱수 정리라고 한다.
 * n이 주어졌을 때 4개 이하의 양의 제곱수의 합으로 n을 만들 수 있는 경우의 수를 구하려고 한다.
 * 경우의 수를 구할 때 제곱수의 순서가 바뀌는 경우는 같은 경우로 본다.
 * 3^2 + 4^2 == 4^2 + 3^2
 * N이 25일때 4개 이하의 제곱수의 합으로 표현 할 수 있는 경우는
 * 1^2 + 2^2 + 2^2 + 4^2, 3^2 + 4^2, 5^2 3가지이다.
 * 
 * 입력
 * 최대 255줄이다. 각 줄에는 2^15보다 작은 양의 정수가 하나씩 주어진다.
 * 마지막줄에는 0이 있고, 입력 데이터가 아니다.
 * 
 * 출력
 * 각 테스트 케이스에 대하여 입력으로 주어진 n을 많아야 4개의 제곱수로 나타내는 경우의 수를 출력
 */
// 시간초과..!!

#include <iostream>

using namespace std;

int n;
int ways;
// 지금까지 재귀를 돌면서 구한 합이 n과 같은 경우 -> 탈출
// 4번 재귀를 돌아도 답을 찾지 못한 경우 -> 탈출

void solve(int start, int count, int sum)
{
	int pow = 0;

	if (sum > n)
		return ;
	if (count == 4)
	{
		if (sum == n)
			ways++;
		return ;
	}
	if (sum == n)
	{
		ways++;
		return ;
	}
	for (int i = start ; i * i <= n ; i++)
		solve(i, count + 1, sum + i * i);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		ways = 0;
		cin >> n;
		if (n == 0)
			break ;
		solve(1, 0, 0);
		cout << ways << "\n";
	}
}
