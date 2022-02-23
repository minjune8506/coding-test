/**
 * 10026 : 적록색약
 * 
 * 적록색약은 빨간색과 초록색의 차리를 거의 느끼지 못한다. 
 * 크기가 N x N인 그리드의 각 칸에 R, G, B중 하나를 색칠한 그림이 있다.
 * 그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다.
 * 또, 같은 색상이 상하좌우 인접해 있는 경우에 두 글자는 같은 구역에 속한다.
 * 그림이 입력으로 주어졌을때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성해라
 * 
 * 입력
 * N (1 <= N <= 100)이 주어지고
 * 그림이 주어진다.
 * 
 * 출력
 * 적록색약이 아닌 사람이 봤을 떄 구역의 갯수
 * 적록색약인 사람이 봤을 때 구역의 갯수를 공백으로 구분해 출력
 */
#include <iostream>

using namespace std;

int N;
bool visited[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int area;
int rg;

void dfs(int x, int y, char **map)
{
	visited[y][x] = true;
	for (int i = 0 ; i < 4 ; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[ny][nx])
			continue ;
		if (map[ny][nx] == map[y][x])
			dfs(nx, ny, map);
	}
}

int main(void)
{
	char **map;

	cin >> N;
	map = new char *[N];
	for (char i = 0 ; i < N ; i++)
		map[i] = new char[N];
	
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
			cin >> map[i][j];
	
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
			if (!visited[i][j])
			{
				dfs(j, i, map);
				area++;
			}
	cout << area << " ";
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
		{
			if (map[i][j] == 'G')
				map[i][j] = 'R';
			visited[i][j] = 0;
		}
	area = 0;
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
		{
			if (!visited[i][j])
			{
				dfs(j, i, map);
				area++;
			}
		}
	cout << area << "\n";
}
