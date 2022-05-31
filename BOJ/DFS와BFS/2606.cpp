/**
 * 2606 : 바이러스
 * 
 * 웜 바이러스는 네트워크를 통해 전파된다. 한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서
 * 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.
 * 
 * 1번 컴퓨터가 웜 바이러스에 걸렸다.
 * 컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게
 * 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.
 * 
 * 입력
 * 컴퓨터의 수 (<= 100)가 주어진다. 각 컴퓨터는 1번 부터 차례대로 번호가 매겨진다.
 * 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다.
 * 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.
 * 
 * 출력
 * 1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를
 * 첫째 줄에 출력한다.
 */

// DFS, BFS 어느 것을 써도 문제가 없을 것으로 보인다.
// 1번 컴퓨터를 통해 갈 수 있는 모든 노드의 갯수를 파악하면 될 것 같다.
#include <iostream>
#include <vector>

using namespace std;

void DFS(bool visited[], int start, vector<int> graph[])
{
	visited[start] = true;
	for (int i = 0 ; i < graph[start].size() ; i++)
	{
		int next = graph[start][i];
		if (visited[next] == false)
			DFS(visited, next, graph);
	}
}

int main(void)
{
	int computer;
	int connected;
	// input
	cin >> computer >> connected;
	
	vector<int> graph[computer + 1];
	bool visitied[computer + 1];
	int answer = 0;

	// graph 연결
	for (int i = 0 ; i < connected ; i++)
	{
		int a, b;

		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	// visited 초기화
	for (int i = 0 ; i < computer + 1; i++)
		visitied[i] = false;
	
	// solve
	DFS(visitied, 1, graph);

	// 방문한 노드의 갯수 구하기
	for (int i = 1 ; i < computer + 1; i++)
		if (visitied[i])
			answer++;
	
	// 1번 노드는 포함하지 않으니 - 1 해서 정답 출력
	cout << answer - 1 << "\n";
}
