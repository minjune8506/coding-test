/**
 * 우선순위 큐
 */

#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	priority_queue<int> maxHeap;

	for (int i = 0 ; i < 5 ; i++)
		maxHeap.push(i);
	cout << "maxHeap Size : " << maxHeap.size() << "\n";
	for (int i = 0 ; i < 5 ; i++)
	{
		cout << maxHeap.top() << "\n";
		maxHeap.pop();
	}
	cout << maxHeap.empty() ? "Empty" : "Not Empty" << "\n";
}
