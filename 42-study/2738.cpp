/**
 * @file 2738.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 행렬 덧셈
 * @date 2023-01-17
 * 
 * N * M 크기의 두 행렬 A와 B가 주어졌을때, 행렬 덧셈 프로그램
 * 
 * N, M < 100, |행렬 원소| < 100
 */
#include <iostream>
#include <vector>

void getMatrixInput(int N, int M, std::vector<int> &matrix) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num;
			std::cin >> num;
			matrix.push_back(num);
		}
	}
}

int main(void) {
	std::vector<int> matrix1;
	std::vector<int> matrix2;
	std::vector<int> answer;

	int N, M;
	std::cin >> N >> M;

	getMatrixInput(N, M, matrix1);
	getMatrixInput(N, M, matrix2);

	for (int i = 0; i < N * M ; i++) {
		answer.push_back(matrix1[i] + matrix2[i]);
	}

	int index = 0;
	for (int i = 0; i < N ; i++) {
		for (int j = 0; j < M; j++) {
			std::cout << answer[index];
			if (j + 1 != M) {
				std::cout << ' ';
			}
			index++;
		}
		std::cout << std::endl;
	}
}
