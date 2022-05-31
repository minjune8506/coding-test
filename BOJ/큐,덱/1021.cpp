/**
 * 1021 : 회전하는 큐
 * 
 * N개의 원소를 포함하고 있는 양방향 순환 큐를 가지고 있다.
 * 이 큐에서 몇개의 원소를 뽑아 내려고 한다. 3가지 연산을 수행할 수 있다.
 * 1. 첫 번째 원소를 뽑아낸다. 이 연산을 수행하면 원래 큐의 원소가 a1, ... , ak
 * 였던 것이 a2, ..., ak와 같이 된다.
 * 2. 왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면 a1, ..., ak가 a2, ..., ak, a1이 된다.
 * 3. 오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면 a1, ..., ak가 ak, a1, ..., ak-1이 된다.
 * 
 * 큐에 처음에 포함되어 있던 수 N이 주어진다.
 * 지민이가 뽑아내려고 하는 원소의 위치가 주어진다.
 * 이때, 그 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값을
 * 출력하는 프로그램을 작성
 * 
 * 입력
 * 첫째 줄에 큐의 크기 N과 뽑아내려고 하는 수의 개수 M이 주어진다.
 * N은  50보다 작거나 같은 자연수이고, M은 N보다 작거나 같은 자연수이다.
 * 둘째 줄에는 지민이가 뽑아내려고 하는 수의 위치가 순서대로 주어진다.
 * 위치는 1보다 크거나 같고, N보다 작거나 같은 자연수이다.
 * 
 * 출력
 * 첫째 줄에 정답을 출력한다.
 */
// 어느 쪽으로 회전시켜야 하는지 어떻게 알 것인가??
// 각각의 원소에 접근할 수 있는가 ? x
// iterator를 이용해 얼마나 가야 target에 도달할 수 있는지 확인.
// deque의 현재 사이즈와 비교해 어느쪽으로 회전할지 결정한다.

#include <iostream>
#include <deque>

using namespace std;

int leftCount;
int rightCount;

void rotateRight(deque<int> &deq)
{
	int x;

	x = deq.back();
	deq.pop_back();
	deq.push_front(x);
	rightCount++;
}

void rotateLeft(deque<int> &deq)
{
	int x;

	x = deq.front();
	deq.pop_front();
	deq.push_back(x);
	leftCount++;
}

int main(void)
{
	int N, M;
	deque<int> deq;
	deque<int>::iterator iter;
	int target;
	int temp;
	int count = 0;

	cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
		deq.push_back(i + 1);
	
	for (int i = 0 ; i < M ; i++)
	{
		cin >> target;
		count = 0;
		iter = deq.begin();
		while (*iter != target)
		{
			count++;
			iter++;
		}
		// cout << "*iter : " << *iter << "\n";
		// cout << "count : " << count << "\n";
		// cout << "Deque Size : " << deq.size() << "\n";
		temp = deq.front();
		if (count <= (deq.size() / 2))
		{
			while (target != temp)
			{
				rotateLeft(deq);
				temp = deq.front();
			}
		}
		else
		{
			while (target != temp)
			{
				rotateRight(deq);
				temp = deq.front();
			}
		}
		// cout << "leftCount : " << leftCount << "\n";
		// cout << "rightCount : " << rightCount << "\n";
		deq.pop_front();
	}
	cout << leftCount + rightCount << "\n";
}
