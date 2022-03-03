/**
 * 1927 : 최소 힙
 * 
 * 최소 힙을 이용하여 다음과 같은 연산을 지원하는 프로그램을 작성하시오.
 * 1. 배열에 자연수 x를 넣는다.
 * 2. 배열에서 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
 * 
 * 입력
 * 연산의 개수(1 <= N <= 100,000)이 주어진다.
 * N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다.
 * 만약 x가 자연수라면 배열에 x라는 값을 넣는 연산이고, x가 0이라면 배열에서 가장 작은 값을 출력하고
 * 배열에서 그 값을 제거하는 경우이다.
 * x는 2^31보다 작은 자연수 또는 0이고, 음의 정수는 입력으로 주어지지 않는다.
 * 
 * 출력
 * 입력에서 0이 주어진 횟수만큼 답을 출력한다.
 * 배열이 비어있을 때 가장 작은 값을 출력하라고 한 경우에는 0을 출력한다.
 */
#include <queue>
#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int> > minHeap;
	int n;

	cin >> n;
	for (int i = 0 ; i < n ; i++)
	{
		int x;

		cin >> x;
		if (x == 0)
		{
			if (minHeap.size() == 0)
				cout << 0 << "\n";
			else
			{
				cout << minHeap.top() << "\n";
				minHeap.pop();
			}
		}
		else
			minHeap.push(x);
	}
}
