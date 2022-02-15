/**
 * 9095 : 1, 2, 3 더하기 
 * 
 * 시간제한 : 1초
 * 정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다.
 * 합을 나타낼 때는 수를 1개이상 사용해야 한다.
 * 1 + 1 + 1 + 1
 * 1 + 1 + 2
 * 1 + 2 + 1
 * 2 + 1 + 1
 * 2 + 2
 * 1 + 3
 * 3 + 1
 * 정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성해라
 * 
 * 입력 
 * 테스트 케이스의 개수 T가 주어진다.
 * 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다.
 * n은 양수이고, 11보다 작다.
 * 
 * 출력
 * n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.
 */
#include <iostream>

using namespace std;

int t, n;
int ways;

void solve(int sum)
{
	if (sum > n)
		return ;
	if (sum == n)
	{
		ways++;
		return ;
	}
	for (int i = 1; i <= 3 ; i++)
		solve(sum + i);
}

int main(void)
{
	cin >> t;
	for (int i = 0 ; i < t ; i++)
	{
		cin >> n;
		ways = 0;
		solve(0);
		cout << ways << "\n";
	}
}
