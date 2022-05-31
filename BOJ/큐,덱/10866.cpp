/**
 * 10866 : 덱
 * 
 * 정수를 저장하는 덱(Deque)를 구현한 다음 명령을 처리하는 프로그램을 작성
 * push_front X: 정수 X를 덱의 앞에 넣는다.
 * push_back X: 정수 X를 덱의 뒤에 넣는다.
 * pop_front : 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 덱에 들어있는 정수가 없는 경우 -1 출력
 * pop_back : 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 덱에 들어있는 정수가 없는 경우 -1 출력
 * size : 덱에 들어있는 정수의 개수를 출력
 * empty : 덱이 비어있으면 1, 아니면 0을 출력
 * front : 덱의 가장 앞에 있는 정수를 출력. 덱에 들어있는 정수가 없는 경우 -1 출력
 * back : 덱의 가장 뒤에 있는 정수를 출력. 덱에 들어있는 정수가 없는 경우 -1 출력
 * 
 * 입력
 * 명령의 수 N (1 <= N <= 10,000)
 * N개의 줄에 명령이 하나씩 주어진다.
 * 1 <= 정수 <= 100,000
 * 문제에 나와있지 않은 명령이 주어지는 경우는 없다.
 * 
 * 출력
 * 출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력
 */

#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	deque<int> deq;
	cin >> N;
	for (int i = 0 ; i < N ; i++)
	{
		string cmd;
		int x;

		cin >> cmd;
		if (cmd == "push_back")
		{
			cin >> x;
			deq.push_back(x);
		}
		else if (cmd == "push_front")
		{
			cin >> x;
			deq.push_front(x);
		}
		else if (cmd == "pop_front")
		{
			if (deq.size())
			{
				x = deq.front();
				cout << x << "\n";
				deq.pop_front();
			}
			else
				cout << -1 << "\n";
		}
		else if (cmd == "pop_back")
		{
			if (deq.size())
			{
				x = deq.back();
				cout << x << "\n";
				deq.pop_back();
			}
			else
				cout << -1 << "\n";
		}
		else if (cmd == "size")
			cout << deq.size() << "\n";
		else if (cmd == "empty")
			cout << deq.empty() << "\n";
		else if (cmd == "front")
		{
			if (deq.size())
				cout << deq.front() << "\n";
			else
				cout << -1 << "\n";
		}
		else if (cmd == "back")
		{
			if (deq.size())
				cout << deq.back() << "\n";
			else
				cout << -1 << "\n";
		}
		else
			continue ;
	}
}
