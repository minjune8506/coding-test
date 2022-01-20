#include <iostream>
#include <queue>

using namespace std;

#define MAX 101

int maze[MAX][MAX];
int visited[MAX][MAX];
int N, M;

typedef struct {
	int x;
	int y;	
} point;

void BFS(int x, int y)
{
	queue<point> q;
	point p = {x, y};
	q.push(p);
	visited[p.x][p.y] = true;
}

int main(void)
{
	cin >> N >> M;
	for (int i = 1 ; i <= N ; i++)
		for (int j = 1; j <= M ; j++)
			scanf("%1d", &maze[i][j]);
	BFS();
}

