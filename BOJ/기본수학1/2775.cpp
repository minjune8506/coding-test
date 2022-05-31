/**
 * 2775 : 부녀회장이 될테야
 * 
 * 각 층의 사람들을 불러 모아 반상회를 주최하려고 한다.
 * a층의 b호에 살려면 자신의 아래 (a - 1)층의 1호부터 b호까지 사람들의
 * 수의 합만큼 사람들을 데려와 살아야 한다는 계약조건이 있다.
 * 비어있는 집은 없고 모든 거주민들이 이 계약 조건을 지키고 있다
 * 주어지는 양의 정수 k와 n에 대해 k층에 n호에는 몇 명이 살고 있는지 출력
 * 단 아파트에는 0층부터 있고 각층에는 1호부터 있으며, 0층의 i호에는 i명이 산다
 * 
 * 입력
 * 첫 번째 줄에 Test case의 수 T가 주어진다. 
 * 각각의 케이스마다 입력으로 첫 번째 줄에 정수 k,
 * 두번째 줄에 정수 n이 주어진다.
 * (1 <= k, n <= 14)
 * 
 * 출력
 * 각각의 Test case에 대해 해당 집에 거주민 수를 출력
 */
// 재귀적인 방법과 반복문을 이용한 풀이 가능
#include <iostream>

using namespace std;

int T;

// 반복문
void solve(int k, int n)
{
	int floor[n + 1];
	for (int i = 1 ; i < n + 1 ; i++)
		floor[i] = i;
	for (int i = k ; i > 0 ; i--)
	{
		for (int j = 2 ; j < n + 1 ; j++)
			floor[j] = floor[j] + floor[j - 1];
	}
	cout << floor[n] << '\n';
}

// 재귀
void solve2(int k, int n, int floor[])
{
	if (k == 0)
		return ;
	for (int i = 2 ; i < n + 1 ; i++)
		floor[i] = floor[i] + floor[i - 1];
	solve2(k - 1, n, floor);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0 ; i < T ; i++)
	{
		int n, k;
		cin >> k >> n;
		// solve(k, n);
		int floor[n + 1];
		for (int i = 1 ; i < n + 1 ; i++)
			floor[i] = i;
		solve2(k, n, floor);
		cout << floor[n] << '\n';
	}
}
