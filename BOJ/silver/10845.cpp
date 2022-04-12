/**
 * 10845 : 큐
 * 
 * 정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램 작성
 * - push X : 정수 X를 큐에 넣는 연산
 * - pop : 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다.
 * 			만약 큐에 들어있는 정수가 없으면 -1 출력
 * - size : 큐에 들어있는 정수의 개수 출력
 * - empty : 큐가 비어있으면 1, 아니면 0을 출력
 * - front : 큐의 가장 앞에 있는 정수를 출력.
 * 			큐에 들어있는 정수가 없는 경우 -1 출력
 * - back : 큐의 가장 뒤에 있는 정수를 출력.
 * 			큐에 들어있는 정수가 없는 경우 -1 출력
 * 
 * 입력
 * 첫째 줄에 주어지는 명령의 수 (1 <= N <= 10,000)이 주어진다.
 * 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다.
 * 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다.
 * 문제에 나와있지 않은 명령이 주어지는 경우는 없다.
 * 
 * 출력
 * 출력해야 하는 명령이 주어질 때마다, 한 줄에 하나씩 출력
 */
#include <iostream>
#include <string>

using namespace std;

class QueueNode{
public:
	int data;
	QueueNode *next;
	QueueNode(int data, QueueNode *next) : data(data), next(next) { }
};

class Queue {
private:
	int size;
	QueueNode *front;
	QueueNode *rear;

public:
	Queue()
	{
		this->size = 0;
		this->front = NULL;
		this->rear = NULL;
	}

	void push(int x)
	{
		QueueNode *newNode = new QueueNode(x, NULL);
		if (size == 0)
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
		size++;
	}

	int pop()
	{
		if (!front)
			return -1;
		QueueNode *tmp = front;
		int data = tmp->data;
		front = tmp->next;
		size--;
		delete tmp;
		return data;
	}

	int getSize()
	{
		return size;
	}

	int empty()
	{
		if (size == 0)
			return 1;
		return 0;
	}

	int getFront()
	{
		if (empty())
			return -1;
		return front->data;
	}

	int getRear()
	{
		if (empty())
			return -1;
		return rear->data;
	}
};

int N;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	Queue *que = new Queue();
	string cmd;

	for (int i = 0 ; i < N ; i++)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			int x;

			cin >> x;
			que->push(x);
		}
		else if (cmd == "pop")
			cout << que->pop() << '\n';
		else if (cmd == "size")
			cout << que->getSize() << '\n';
		else if (cmd == "empty")
			cout << que->empty() << '\n';
		else if (cmd == "front")
			cout << que->getFront() << '\n';
		else if (cmd == "back")
			cout << que->getRear() << '\n';
		else
			cout << "error" << '\n';
	}	
}
