/**
 * 1655 : 가운데를 말해요
 * 
 * 정수를 하나 외칠때마다 동생은 지금까지 백준이가 말한 수 중에서 중간값을
 * 말해야 한다. 만약, 그동안 백준이가 외친 수의 개수가 짝수개라면
 * 중간에 있는 두 수 중에서 작은 수를 말해야 한다.
 * 백준이가 외치는 수가 주여졌을 때, 동생이 말해야 하는 수를 구하는 프로그램을 작성하시오.
 * 
 * 입력
 * 첫째 줄에 백준이가 외치는 정수의 개수 N이 주어진다.
 * N은 1보다 크거나 같고, 100,000보다 작거나 같은 자연수이다.
 * 그 다음 N줄에 걸쳐 백준이가 외치는 정수가 차례대로 주어진다.
 * 정수는 -10,000보다 크거나 같고 10,000보다 작거나 같다.
 * 
 * 출력
 * 한 줄에 하나씩 N줄에 걸쳐 백준이의 동생이 말해야 한느 수를 순서대로 출력한다.
 */
// 최소, 최댓값을 최소힙, 최대힙을 이용하여 구한다.
// 최대 힙의 값들은 최소 힙의 값들보다 작다.
// 최대 힙과 최소힙에 번갈아가면서 값을 추가한다.
// top을 비교해서 최대힙의 top이 더 크면 최소힙의 top과 swap한다.
// maxHeap의 top은 언제나  중간값이다.

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

	priority_queue<int, vector<int>, greater<int> > minHeap;
	priority_queue<int, vector<int> > maxHeap;

	cin >> N;
	for (int i = 0 ; i < N ; i++)
	{
		int num;

		cin >> num;
		if (i % 2 == 0)
			maxHeap.push(num);
		else
			minHeap.push(num);
		if (minHeap.size() && maxHeap.top()  > minHeap.top())
		{
			int temp = minHeap.top();
			minHeap.pop();
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(temp);
		}
		cout << maxHeap.top() << "\n";
	}
}
