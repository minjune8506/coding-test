/**
 * @file 10828.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 스택
 * @date 2023-02-09
 *
 * 정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는
 * 프로그램
 *
 * push X : 정수 X를 스택에 넣는 연산
 * pop : 스택 가장 위의 정수를 뺴고, 그 수를 출력한다. 스택이 비어있는 경우 -1
 * 출력 size : 스택에 들어있는 정수의 개수를 출력 empty : 스택이 비어있으면 1,
 * 아니면 0을 출력 top : 가장 위에 있는 정수를 출력한다. 스택에 들어있는 정수가
 * 없는 경우 -1 출력
 *
 * Linked List를 이용한 구현
 */
#include <iostream>

struct Node {
	int data;
	struct Node *next;

	Node(int x) : data(x), next(nullptr) {}
};

class Stack {
   private:
	Node *head;
	int count;

   public:
	Stack() : head(nullptr), count(0) {}

	void push(int x) {
		Node *newNode = new Node(x);
		if (head) {
			Node *temp = head;
			newNode->next = temp;
			head = newNode;
		} else {
			head = newNode;
		}
		count++;
	}

	void pop() {
		if (head) {
			Node *temp = head;
			head = head->next;
			std::cout << temp->data << '\n';
			delete temp;
			count--;
			return;
		}
		std::cout << -1 << '\n';
	}

	void size() { std::cout << count << '\n'; }

	void empty() { std::cout << (count <= 0 ? 1 : 0) << '\n'; }

	void top() {
		if (head) {
			std::cout << head->data << '\n';
			return;
		}
		std::cout << -1 << '\n';
	}
};

int main(void) {
	int N;
	Stack s;

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::string command;

		std::cin >> command;

		if (command == "push") {
			int x;
			std::cin >> x;
			s.push(x);
		} else if (command == "pop") {
			s.pop();
		} else if (command == "size") {
			s.size();
		} else if (command == "empty") {
			s.empty();
		} else if (command == "top") {
			s.top();
		}
	}
	std::cout << std::endl;
}
