/**
 * @file 10866.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 덱
 * @date 2023-02-09
 *
 * 정수를 저장하는 Deque를 구현한 다음 명령을 처리해라
 * push_front X: 정수 X를 덱의 앞에 넣는다.
 * push_back X: 정수 X를 덱의 뒤에 넣는다.
 * pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * size: 덱에 들어있는 정수의 개수를 출력한다. empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
 * front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 */
#include <iostream>

struct Node {
	int data;
	struct Node *next;
	struct Node *prev;

	Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};

class Deque {
   private:
	Node *head;
	Node *tail;
	int count;

   public:
	Deque() : head(nullptr), tail(nullptr), count(0) {}

	void push_front(int x) {
		Node *newNode = new Node(x);
		if (!head && !count) {
			head = newNode;
			tail = newNode;
		} else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		count++;
	}

	void push_back(int x) {
		Node *newNode = new Node(x);
		if (!head && !count) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		count++;
	}

	void pop_front() {
		if (head) {
			Node *temp = head;
			head = head->next;
			if (!head) {
				tail = nullptr;
			} else {
				head->prev = nullptr;
			}
			std::cout << temp->data << '\n';
			delete temp;
			count--;
		} else {
			std::cout << -1 << '\n';
		}
	}

	void pop_back() {
		if (tail) {
			Node *temp = tail;
			tail = tail->prev;
			if (!tail) {
				head = nullptr;
			} else {
				tail->next = nullptr;
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
	Deque dq;

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::string command;

		std::cin >> command;
		if (command == "push_front") {
			int x;
			std::cin >> x;
			dq.push_front(x);
		} else if (command == "push_back") {
			int x;
			std::cin >> x;
			dq.push_back(x);
		} else if (command == "pop_front") {
			dq.pop_front();
		} else if (command == "pop_back") {
			dq.pop_back();
		} else if (command == "front") {
			dq.front();
		} else if (command == "back") {
			dq.back();
		} else if (command == "size") {
			dq.size();
		} else if (command == "empty") {
			dq.empty();
		}
	}
}
