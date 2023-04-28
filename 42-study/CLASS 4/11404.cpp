/**
 * @file 11404.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 플로이드
 * @date 2023-04-28
 *
 * N (2 <= n <= 100)개의 도시가 있다.
 * 한 도시에서 출발해서 다른 도시에 도착하는 M (1 <= M <= 100,000
 * 개의 버스가 있따.
 * 모든 도시 쌍(A, B)에 대해 비용의 최솟값
 * A, B로 가는 간선은 하나가 아닐 수 있다.
 *
 * 플로이드 워셜 알고리즘
 * - 다익스트라와는 다르게 음의 간선도 이용 가능
 * - 2차원 인접 행렬 이용
 */
#include <climits>
#include <cstring>
#include <iostream>
#include <vector>

int N, M;

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	long long graphs[N + 1][N + 1];

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			graphs[i][j] = INT_MAX;
			if (i == j) {
				graphs[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int start, end, weight;

		std::cin >> start >> end >> weight;
		graphs[start][end] = std::min((int)graphs[start][end], weight);
	}

	for (int k = 1; k <= N; k++) {
		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= N; b++) {
				long long x = graphs[a][k] + graphs[k][b];
				int y = graphs[a][b];
				graphs[a][b] = x > y ? y : x;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (graphs[i][j] == INT_MAX) {
				std::cout << 0 << ' ';
			} else {
				std::cout << graphs[i][j] << ' ';
			}
		}
		std::cout << '\n';
	}
}
