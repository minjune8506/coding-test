/**
 * @file 1018.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 체스판 다시 칠하기
 * @date 2023-01-25
 * 
 * 체스판은 검은색 흰색이 번갈아서 칠해져 있어야 한다.
 * 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우 두가지 경우가 있다.
 * 보드가 체스판처럼 칠해져 있다는 보장이 없기 때문에
 * 8x8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야 한다.
 * 다시 칠해야 하는 정사각형의 최소 개수를 구해라.
 * 
 * 1. N과 M을 입력받는다. (8 <= N, M < 50)
 * 2. 보드를 입력받는다. B는 검은색, W는 흰색이다.
 * 3. 각각을 비교하면서 몇개를 다시 칠해야 하는지 구한다.
 * 4. 최솟값을 구한다.
 */
#include <iostream>
#include <string>
#include <vector>
#include <climits>

char case1[64] = {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
					'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
					'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
					'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
					'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
					'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
					'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
					'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'};

char case2[64] = {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
					'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
					'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
					'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
					'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
					'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
					'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
					'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'};
int N, M;

int countMismatch(std::vector<char> &board, int i, int j) {
	int index = 0;
	int case1Count = 0;
	int case2Count = 0;

	for (int y = i; y < i + 8; y++) {
		for (int x = j; x < j + 8; x++) {
			if (board[y * M + x] != case1[index]) {
				case1Count++;			
			}
			if (board[y * M + x] != case2[index]) {
				case2Count++;
			}
			index++;
		}
	}
	return std::min(case1Count, case2Count);
}

int main(void) {

	std::cin >> N >> M;
	std::vector<char> board;
	for (int i = 0; i < N * M; i++) {
		char c;

		std::cin >> c;
		board.push_back(c);
	}
	
	int min = INT_MAX;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int count = countMismatch(board, i, j);
			if (count < min) {
				min = count;
			}
		}
	}

	std::cout << min << std::endl;
}
