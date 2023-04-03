/**
 * @file 1991.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 트리 순회
 * @date 2023-04-03
 *
 * preorder traversal
 * inorder traversal
 * postorder traversal 결과를 출력하는 프로그램
 *
 * 노드의 개수 1 <= N <= 26
 */
#include <iostream>
#include <map>

void preOrder(std::map<char, std::pair<char, char> > &tree, char curr) {
	if (curr == '.') {
		return;
	}
	std::cout << curr;
	preOrder(tree, tree[curr].first);
	preOrder(tree, tree[curr].second);
}

void inOrder(std::map<char, std::pair<char, char> > &tree, char curr) {
	if (curr == '.') {
		return;
	}
	inOrder(tree, tree[curr].first);
	std::cout << curr;
	inOrder(tree, tree[curr].second);
}

void postOrder(std::map<char, std::pair<char, char> > &tree, char curr) {
	if (curr == '.') {
		return;
	}
	postOrder(tree, tree[curr].first);
	postOrder(tree, tree[curr].second);
	std::cout << curr;
}

int main(void) {
	int N;

	std::cin >> N;
	std::map<char, std::pair<char, char> > tree;

	for (int i = 0; i < N; i++) {
		char data, left, right;

		std::cin >> data >> left >> right;
		tree.insert(std::make_pair(data, std::make_pair(left, right)));
	}
	preOrder(tree, 'A');
	std::cout << '\n';
	inOrder(tree, 'A');
	std::cout << '\n';
	postOrder(tree, 'A');
	std::cout << '\n';
}
