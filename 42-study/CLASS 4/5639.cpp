/**
 * @file 5639.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 이진 검색 트리
 * @date 2023-04-08
 *
 * 이진 검색 트리를 전위순회한 결과가 주어지면
 * 후위 순회한 결과를 출력해라
 * 
 * 이진 검색 트리를 구현해서 직접 후위순회하는 방법으로 품
 * 
 * 다른 풀이
 * - 전위 순회는 무조건 처음나오는 값이 root
 * - root보다 작은 값 -> 왼쪽 서브 트리
 * - root보다 큰 값 -> 오른쪽 서브 트리
 * - 재귀적으로 계속 탐색 -> 왼쪽 오른쪽 나 순서대로 출력
 */
#include <iostream>
#include <vector>

class Node {
   public:
	int key;
	Node *left;
	Node *right;

	Node(int key) : key(key), left(NULL), right(NULL) {}
};

class Tree {
   public:
	Node *root;

	void add(int key) {
		Node *node = new Node(key);
		if (!root) {
			root = node;
			return;
		}

		Node *parent;
		Node *temp = root;
		while (temp != nullptr) {
			parent = temp;
			if (temp->key < key) {
				temp = temp->right;
			} else {
				temp = temp->left;
			}
		}
		if (parent->key < key) {
			parent->right = node;
		} else {
			parent->left = node;
		}
	}

	void inOrder(Node *root) {
		if (!root) {
			return;
		}
		std::cout << root->key << ' ';
		inOrder(root->left);
		inOrder(root->right);
	}

	void postOrder(Node *root) {
			if (!root) {
			return;
		}
		postOrder(root->left);
		postOrder(root->right);
		std::cout << root->key << '\n';
	}
};

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	Tree *tree = new Tree();

	while (true) {
		int key;

		std::cin >> key;
		if (std::cin.eof()) {
			break;
		}
		tree->add(key);
	}
	tree->postOrder(tree->root);
}
