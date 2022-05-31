/**
 * 2667 : 단지번호붙이기
 * 
 * 정사각형 모양의 지도가 있다. 1은 집이 있는 곳, 0은 집이 없는 곳을 나타낸다.
 * 철수는 이 지도를 가지고 연결되 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다.
 * 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다.
 * 대각선상에 집이 있는 경우는 연결된 것이 아니다.
 * 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여
 * 출력하는 프로그램을 작성하시오.
 * 
 * 입력
 * 첫 번째 줄 : 지도의 크기 N(정사각형, 5 <= N <= 25)이 입력
 * N줄 : N개의 자료 (0 혹은 1)가 입력된다.
 * 
 * 출력
 * 총 단지수
 * 각 단지 내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력
 * 
 * 시간제한 : 1초
 */

/**
 * 풀이
 * 2차원 배열의 모든 원소에 대해 원소의 값이 1이고, 아직 방문하지 않은 원소만 dfs를 수행한다.
 * 상하좌우에 있는 map의 값이 1(집인 것)이고, 아직 방문하지 않은 노드를 찾아서 dfs를 다시 수행하고
 * 마지막 리턴값을 연결되어 있는 집의 개수로 한다.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, house;
bool visited[25][25];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<int> answer;

int dfs(int x, int y, int **map)
{
	int nx, ny;

	house++;
	visited[y][x] = true;
	for (int i = 0 ; i < 4 ; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[ny][nx])
			continue ;
		if (map[ny][nx])
			dfs(nx, ny, map);
	}
	return (house);
}

int main(void)
{
	cin >> N;

	// memory allocation	
	int **map = new int *[N];
	for (int i = 0 ; i < N ; i++)
		map[i] = new int [N];
	
	// input
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
			scanf("%1d", &map[i][j]);
	
	// solve
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
			if (map[i][j] && visited[i][j] == false)
			{
				house = 0;
				answer.push_back(dfs(j, i, map));
			}
	
	// sort
	sort(answer.begin(), answer.end());

	// output
	cout << answer.size() << "\n";
	for (int i = 0 ; i < answer.size() ; i++)
		cout << answer[i] << "\n";
}
