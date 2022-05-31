/**
 * 1012 : 유기농 배추
 * 
 * 시간제한 1초
 * 
 * 한나는 강원도 고랭지에서 유기농 배추를 재배하기로 하였다.
 * 농약을 쓰지 않고 배추를 재배하려면 배추를 해충으로부터 보호하는 것이 중요해서, 배추 흰지렁이를 구입하기로 결심했다.
 * 어떤 배추에 지렁이가 한 마리라도 살고 있으면 이 지렁이는 인접한 다른 배추로 이동할 수 있어, 그 배추들 역시 해충으로부터 보호받을 수 있다.
 * 한 배추의 상하좌우 네 방향에 다른 배추가 위치한 경우에 서로 인접해 있는 것이다.
 * 배추를 재배하는 땅은 고르지 못해서 배추를 군데군데 심어 놓았다.
 * 배추들이 모여있는 곳에는 지렁이 한마리만 있으면 되므로 인접해있는 배추들이 몇군데에 퍼져있는지 조사하면 총 몇마리의 지렁이가 필요한지 알 수 있다.
 * 
 * 입력
 * 첫줄 : 테스트케이스의 개수 T
 * 각각의 테스트 케이스에 대해
 * 배추밭의 가로길이 M (1 <= M <= 50) 세로길이 N (1 <= N <= 50) 배추가 심어져 있는 위치의 개수 K (1 <= K <= 2500)이 주어진다.
 * 다음 K줄에는 배추의 위치 X (0 <= X <=  M - 1), Y (0 <= Y <= N - 1)가 주어진다.
 * 두 배추의 위치가 같은 경우는 없다.
 * 
 * 출력 
 * 필요한 최소의 배추흰지렁이 마리 수를 출력
 */
#include <iostream>

using namespace std;

int T, M, N, K;
int visited[50][50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int **createLand(int M, int N)
{
	int **land;

	land = new int *[N];
	for (int i = 0 ; i < N ; i++)
		land[i] = new int [M];
	
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			land[i][j] = 0;
	
	return (land);
}

void reset(int M, int N)
{
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			visited[i][j] = false;
}

int dfs(int x, int y, int **land)
{
	int nx, ny;

	visited[y][x] = true;
	for (int i = 0; i < 4 ; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N || visited[ny][nx])
			continue ;
		if (land[ny][nx])
			dfs(nx, ny, land);
	}
	return (1);
}

int main(void)
{
	cin >> T;
	for (int i = 0 ; i < T ; i++)
	{
		int **land;
		int answer = 0;
		
		cin >> M >> N >> K;
		reset(M, N);
		land = createLand(M, N);		
		for (int j = 0 ; j < K ; j++)
		{
			int X, Y;
			cin >> X >> Y;
			land[Y][X] = 1;
		}
		for (int j = 0 ; j < N ; j++)
			for (int k = 0 ; k < M ; k++)
				if (land[j][k] && visited[j][k] != true)
					answer += dfs(k, j, land);
		cout << answer << "\n";
	}
}
