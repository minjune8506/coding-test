/**
 * 2178 : 미로탐색
 * 
 * N * M 크기의 배열로 표현되는 미로가 있다.
 * 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다.
 * 미로가 주어졌을 떄, (1, 1)에서 출발하여 (N, M)위치로 이동할 떄 지나야 하는 최소의 칸 수를 구하는 프로그램
 * 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸만 이동할 수 있다.
 * 
 * 입력
 * 첫째 줄에 두 정수 N, M(2 <= N, M <= 100)이 주어진다.
 * 다음 N개의 줄에는 M개의 정수로 미로가 주어진다.
 * 각각의 수들은 붙어서 입력으로 주어진다.
 * 
 * 출력
 * 첫째 줄에 지나야 하는 최소의 칸 수르 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
 */

// 최단경로를 구하는 문제이므로 BFS를 이용하여 풀어야 한다.
// 0,0 시작 인접한 갈 수 있는 노드를 큐에 넣는다.
// 큐의 맨앞 노드를 꺼내서 갈 수 있는 곳을 큐에 넣는다.
// 꺼낸 노드의 저장된 거리 + 1를 큐에서 갈 수 있는 곳의 위치에 넣는다.

#include <iostream>
#include <queue>

using namespace std;
typedef struct point
{
	int x;
	int y;
}point;

int N , M;
int visited[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


void bfs(int x, int y, int **map)
{
	queue<point> que;
	point pt = {x, y};
	point temp;
	int ways = 0;

	visited[y][x] = true;
	que.push(pt);
	while (!que.empty())
	{
		ways= 0;
		temp = que.front();
		que.pop();
		for (int i = 0 ; i < 4 ; i++)
		{
			int nx = temp.x + dx[i];
			int ny = temp.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N || visited[ny][nx])
				continue ;
			if (map[ny][nx])
			{
				point newPoint = {nx, ny};
				que.push(newPoint);
				map[ny][nx] = map[temp.y][temp.x] + 1;
				visited[ny][nx] = true;
				ways++;
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;
	int **map;

	map = new int *[N];
	for (int i = 0 ; i < N ; i++)
		map[i] = new int[M];
	
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			scanf("%1d", &map[i][j]);
	
	bfs(0, 0, map);
	cout << map[N -1][M - 1] << "\n";
}
