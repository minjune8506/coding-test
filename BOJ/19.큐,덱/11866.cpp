/**
 * 11866 : 요세푸스 문제 0
 * 
 * 1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K (<= N)이 주어진다.
 * 순서대로 K번째 사람을 제거한다. 한사람이 제거됨녀 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다.
 * 이 과정은 N명의 사람이 모두 제거될 때까지 반복된다.
 * 원에서 사람들이 제거되는 순서를 (N, K) - 요세푸스 순열이라고 한다.
 * 
 * 입력
 * N K가 주어진다. (1 <= K <= N <= 1,000)
 * 
 * 출력
 * 요세푸스 순열을 출력
 */

/**
 * 7 3
 * 1 2 3 4 5 6 7 -> 3
 * 4 5 6 7 1 2 -> 6
 * 7 1 2 4 5 -> 2
 * 4 5 7 1 -> 7
 * 1 4 5 -> 5
 * 1 4 -> 1
 * 4 -> 4
 * 
 * K - 1개의 원소를 뺴서 뒤로 넣는다 (1)
 * K 번째 원소를 제거한다. (2)
 * 큐가 비어있을 때까지 반복한다. (3)
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
	int N, K;
	queue<int> que;
	vector<int> answer;

	// input
	cin >> N >> K;
	
	// solve
	for (int i = 1 ; i <= N ; i++)
		que.push(i);
	while (!que.empty())
	{
		for (int i = 0 ; i < K - 1 ; i++)
		{
			int rotate;

			rotate = que.front();
			que.pop();
			que.push(rotate);
		}
		answer.push_back(que.front());
		que.pop();
	}

	// output
	cout << "<";
	for (int i = 0 ; i < N ; i++)
	{
		cout << answer[i];
		if (i != N - 1)
			cout << ", ";
	}
	cout << ">" << "\n";
}
