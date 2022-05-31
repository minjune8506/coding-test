/**
 * 11279 : 최대힙
 * 
 * 최대 힙을 이용하여 다음과 같은 연산을 지원하는 프로그램을 작성하시오.
 * 1. 배열에 자연수 x를 넣는다.
 * 2. 그 배열에서 가장 큰 값을 출력하고, 그 값을 배열에서 제거한다.
 * 프로그램은 처음에 비어있는 배열에서 시작하게 된다.
 * 
 * 입력
 * 연산의 개수 N (1 <= N <= 100,000)이 주어진다.
 * N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다.
 * x가 자연수라면 배열에 x라는 값을 넣는 연산이고,
 * x가 0이라면 배열에서 가장 큰 값을 출력하고 그 값을 배열에서 제거하는 경우이다.
 * 입력되는 자연수는 2^31보다 작다.
 * 
 * 출력
 * 입력에서 0이 주어진 회수만큼 답을 출력한다.
 * 배열이 비어 있는 경우인데 가장 큰 값을 출력할 경우 0을 출력하면 된다.
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int> maxHeap;
	cin >> N;
	for (int i = 0 ; i < N ; i++)
	{
		int num;

		cin >> num;
		if (!num)
		{
			if (!maxHeap.size())
				cout << 0 << "\n";
			else
			{
				cout << maxHeap.top() << "\n";
				maxHeap.pop();
			}
		}
		else
			maxHeap.push(num);
	}
}
