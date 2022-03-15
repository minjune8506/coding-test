/**
 * 15650 : N과 M (2)
 * 
 * 자연수 N과 M이 주어졌을 떄, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는
 * 프로그램을 작성하시오.
 * - 1부터 N까지 자연수 중에서 중복없이 M개를 고른 수열
 * - 고른 수열은 오름차순이어야 한다.
 *
 * 입력
 * 첫째 줄에 자연수 N과 M이 주어진다. (1 <= M <= N <= 8)
 *
 * 출력
 * 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다.
 * 중복되는 수열은 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력한다.
 * 수열은 사전 순으로 증가하는 순서로 출력해야 한다.
 */
#include <iostream>

int N, M;
int ary[9] = {0, };
bool visited[9] = {0, };

using namespace std;

void dfs(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M - 1; i++)
		{
			if (ary[i] > ary[i + 1])
				return;
		}
		for (int i = 0; i < M; i++)
		{
			cout << ary[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			ary[cnt] = i + 1;
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}

int main(void)
{
	cin >> N >> M;
	dfs(0);
}
