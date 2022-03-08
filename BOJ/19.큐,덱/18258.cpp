/**
 * 18258 : 큐 2
 * 
 * 정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하라.
 * push X : 정수 X를 큐에 넣는 연산이다.
 * pop : 큐에서 가장 앞에 있는 정수를 뺴고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에 -1 출력
 * size : 큐에 들어있는 정수의 개수를 출력
 * empty : 큐가 비어있으면 1, 아니면 0을 출력
 * front : 큐의 가장 앞에있는 정수를 출력. 만약 큐에 들어있는 정수가 없는 경우 -1 출력
 * back : 큐의 가장 뒤에 있는 정수를 출력, 만약 큐에 들어있는 정수가 없는 경우 -1 출력
 * 
 * 입력
 * 명령의 수 N (1 <= N <= 2,000,000)
 * N개의 줄에 명령이 하나씩 주어진다. 정수는 1보다 크거나 같고, 100,000보다 작거나 같다.
 * 
 * 출력
 * 출력해야하는 명령이 주어질 떄마다, 한 줄에 하나씩 출력
 */
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string cmd;
	queue<int> que;
	int N;

	cin >> N;
	for (int i = 0 ; i < N ; i++)
	{
		int x;

		cin >> cmd;
		if (cmd == "push")
		{
			cin >> x;
			que.push(x);
		}
		else if (cmd == "front")
		{
			int front = -1;
			
			if (que.size())
				front = que.front();
			cout << front << "\n";
		}
		else if (cmd == "back")
		{
			int back = -1;
			if (que.size())
				back = que.back();
			cout << back << "\n";
		}
		else if (cmd == "size")
			cout << que.size() << "\n";
		else if (cmd == "empty")
			cout << que.empty() << "\n";
		else if (cmd == "pop")
		{
			int pop = -1;
			
			if (que.size())
			{
				pop = que.front();
				que.pop();
			}
			cout << pop << "\n";
		}
	}		
}
