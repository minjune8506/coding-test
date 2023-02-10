/**
 * @file 10845.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 큐
 * @date 2023-02-09
 *
 * 정수를 저장하는 큐를 구현한 다음, 명령얼 처리하는 프로그램
 *
 * - push X : 정수 X를 큐에 넣는다.
 * - pop X : 큐에서 가장 앞에 있는 정수를 빼고, 출력. 큐가 비었다면 -1 출력
 * - size : 큐에 들어있는 정수의 개수 출력
 * - empty : 큐가 비어있으면 1, 아니면 0 출력
 * - front : 큐의 가장 앞에 있는 정수 출력. 비었다면 -1 출력
 * - back : 큐의 가장 뒤에 있는 정수 출력. 비었다면 -1 출력
 */
#include <iostream>

struct Node {
	int data;
	struct Node *next;

	Node(int x) : data(x), next(nullptr) {}
};

class Queue {
   private:
	Node *head;
	Node *tail;
	int count;

   public:
	Queue() : head(nullptr), tail(nullptr), count(0) {}

	void push(int x) {
		Node *newNode = new Node(x);
		if (!head && !count) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
		count++;
	}

	void pop() {
		if (head) {
			Node *temp = head;
			head = head->next;
			if (!head) {
				tail = nullptr;
			}
			std::cout << temp->data << '\n';
			delete temp;
			count--;
		} else {
			std::cout << -1 << '\n';
		}
	}

	void size() { std::cout << count << '\n'; }

	void empty() { std::cout << (count <= 0 ? 1 : 0) << '\n'; }

	void front() {
		if (head) {
			std::cout << head->data << '\n';
			return;
		}
		std::cout << -1 << '\n';
	}

	void back() {
		if (tail) {
			std::cout << tail->data << '\n';
			return;
		}
		std::cout << -1 << '\n';
	}
};

int main(void) {
	int N;
	Queue q;

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::string command;

		std::cin >> command;
		if (command == "push") {
			int x;
			std::cin >> x;
			q.push(x);
		} else if (command == "pop") {
			q.pop();
		} else if (command == "front") {
			q.front();
		} else if (command == "back") {
			q.back();
		} else if (command == "size") {
			q.size();
		} else if (command == "empty") {
			q.empty();
		}
	}
}
