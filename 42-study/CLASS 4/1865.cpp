/**
 * @file 1865.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 웜홀
 * @date 2023-05-08
 *
 * N개의 지점이 있고 M개의 도로와 W개의 웜홀이 있다.
 * 도로는 방향이 없고, 웜홀은 방향이 있다.
 *
 * 웜홀은 시작위치 -> 도착위치로 가는 하나의 경로
 * 도착을 하게되면 시간이 뒤로가게 된다. (시간이 거꾸로 간다)
 * 음의 가중치를 가짐 -> 벨만 포드 알고리즘 사용
 *
 * 한 지점에서 출발하여 시간여행을 하기 시작한 후
 * 다시 출발한 위치로 돌아올때, 시간이 돌아간 경우가 있는지 없는지?
 *
 * 테스트 케이스 TC (1 <= TC <= 5)
 * 지점의 수 N(1 <= N <= 500)
 * 도로의 수 M(1 <= M <= 2500)
 * 웜홀의 수 W(1 <= W <= 200)
 *
 * S, E, T
 * 연결된 지점의 번호, 걸리는 시간
 */
#include <iostream>
#include <vector>

#define ROAD 0
#define HOLE 1
#define MAX 999999999

typedef struct s_Node {
	int start;
	int end;
	int weight;
	int type;
} t_Edge;

bool bf(int N, std::vector<t_Edge> edges) {
	int dist[N + 1];
	for (int i = 1; i <= N; i++) {
		dist[i] = MAX;
	}
	dist[1] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < edges.size(); j++) {
			int from = edges[j].start;
			int to = edges[j].end;
			int cost = edges[j].weight;
			if (edges[j].type == HOLE) {
				cost *= -1;
			}

			if (dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < edges.size(); j++) {
			int from = edges[j].start;
			int to = edges[j].end;
			int cost = edges[j].weight;
			if (edges[j].type == HOLE) {
				cost *= -1;
			}

			if (dist[to] > dist[from] + cost) {
				return true;
			}
		}
	}
	return false;
}

void solve() {
	int N, M, W;
	std::cin >> N >> M >> W;

	std::vector<t_Edge> edges;

	for (int i = 0; i < M; i++) {
		int S, E, T;
		std::cin >> S >> E >> T;
		edges.push_back({S, E, T, ROAD});
		edges.push_back({E, S, T, ROAD});
	}

	for (int i = 0; i < W; i++) {
		int S, E, T;
		std::cin >> S >> E >> T;
		edges.push_back({S, E, T, HOLE});
	}
	if (bf(N, edges)) {
		std::cout << "YES" << '\n';
		return;
	}
	std::cout << "NO" << '\n';
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int TC;
	std::cin >> TC;
	for (int i = 0; i < TC; i++) {
		solve();
	}
}
