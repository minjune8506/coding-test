/**
 * @file 2630.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 색종이 만들기
 * @date 2023-02-24
 *
 * 여러개의 칸들로 이루어진 정사각형 모양의 종이가 있다.
 * 각 정사각형은 하얀색 / 파란색으로 칠해져 있다.
 * 주어진 종이를 일정한 규칙에 따라 잘라 다양한 크기를 가진
 * 정사각형 모양의 하얀색 / 파란색 종이를 만드려고 한다.
 *
 * 전체 종이의 한 변의 길이 N
 * N IN (2, 4, 8, 16, 32, 64, 128)
 * 하얀색 : 0 / 파란색 : 1
 */
#include <iostream>
#include <vector>

#define WHITE 0
#define BLUE 1

int countWhite = 0;
int countBlue = 0;

bool isSameColor(int **paper, int N, int x, int y, int size) {
	int color = paper[y][x];

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (color != paper[i][j]) {
				return false;
			}
		}
	}
	if (color == WHITE) {
		countWhite++;
		return true;
	}
	countBlue++;
	return true;
}

void solve(int **paper, int N, int x, int y, int size) {
	if (size < 1 || x >= N || y >= N || x < 0 || y < 0) {
		return;
	}
	if (isSameColor(paper, N, x, y, size)) {
		return;
	}
	solve(paper, N, x, y, size / 2);
	solve(paper, N, x + size / 2, y, size / 2);
	solve(paper, N, x, y + size / 2, size / 2);
	solve(paper, N, x + size / 2, y + size / 2, size / 2);
}

int main(void) {
	int N;

	std::cin >> N;
	int **paper = new int *[N];
	for (int i = 0; i < N; i++) {
		paper[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int color;
			std::cin >> color;
			paper[i][j] = color;
		}
	}
	solve(paper, N, 0, 0, N);
	std::cout << countWhite << '\n' << countBlue << std::endl;

	for (int i = 0; i < N; i++) {
		delete[] paper[i];
	}
	delete[] paper;
}
