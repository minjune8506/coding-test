/**
 * 2583 : 영역 구하기
 * 
 * 눈금의 간격이 1인 M x N (M, N <= 100)크기의 모눈종이가 있다.
 * 이 모눈종이 위의 눈금에 맞추서 K개의 직사각형을 그릴 때, 이들 K개의 직사각형의 내부를 제외한 나머지
 * 부분이 몇개의 분리된 영역으로 나누어진다.
 * M, N, K 그리고 K개의 직사각형의 좌표가 주어질 때, K개의 직사각형 내부를 제외한 나머지 부분이 몇 개의
 * 분리된 영역으로 나누어지는지, 그리고 분리된 영역의 넓이가 얼마인지를 구하여 이를 출력하는 프로그램을 작성하라
 * 
 * 입력
 * M, N, K 가 주어지고 모두 100 이하의 자연수이다.
 * K개의 줄에 한 줄에 하나씩 직사각형의 왼쪽 아래 꼭짓점의 x,y 좌표값과 오른쪽 위 꼭짓점의
 * x, y 좌표값이 빈칸을 두고 차례로 주어진다.
 * 모눈종이 왼쪽 아래 꼭짓점의 좌표는 (0, 0)이고, 오른쪽 위의 꼭짓점의 좌표는 (N, M)이다.
 * 입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.
 * 
 * 출력
 * 분리되어 나누어지는 영역의 개수
 * 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;
bool visited[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int area;
vector<int> answer;

void dfs(int x, int y, int **map)
{
	visited[y][x] = true;
	area++;
	for (int i = 0 ; i < 4 ; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[ny][nx])
			continue ;
		if (!map[ny][nx])
			dfs(nx, ny, map);
	}
}

int main(void)
{
	int **map;

	// input
	cin >> M >> N >> K;

	// memory allocation
	map = new int *[M];
	for (int i = 0 ; i < M ; i++)
		map[i] = new int[N];

	// initialize
	for (int i = 0 ; i < M ; i++)
		for (int j = 0 ; j < N ; j++)
			map[i][j] = 0;
		
	// input
	for (int i = 0 ; i < K; i++)
	{
		int x, y, x1, y1;

		cin >> x >> y >> x1 >> y1;
		for (int k = M - y1 ; k < M - y ; k++)
			for (int j = x ; j < x1 ; j++)
				map[k][j] = 1;
	}

	// dfs
	for (int i = 0 ; i < M ; i++)
	{
		for (int j = 0 ; j < N ; j++)
		{
			if (!map[i][j] && !visited[i][j])
			{
				area = 0;
				dfs(j, i, map);
				answer.push_back(area);
			}
		}
	}
	
	// sort & data output
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0 ; i < answer.size() ; i++)
		cout << answer[i] << " ";
	cout << "\n";
}
