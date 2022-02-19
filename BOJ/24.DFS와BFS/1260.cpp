/**
 * 1260 : DFS와 BFS
 * 
 * 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성.
 * 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고,
 * 더 이상 방문할 수 있는 정점이 없는 경우 종료한다.
 * 정점 번호는 1번부터 N번까지이다.
 * 
 * 입력
 * 정점의 개수 N(1 <= N <= 1000), 간선의 개수 M (1 <= M <= 10,000), 탐색을 시작할 정점의 번호 V가 주어진다.
 * M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다.
 * 어떤 두 정점 사이에는 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.
 * 
 * 출력
 * DFS를 수행한 결과
 * BFS를 수행한 결과
 * V부터 방문된 점을 순서대로 출력하면 된다. 
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;

void reset(bool visited[])
{
	for (int i = 0 ; i < N + 1 ; i++)
		visited[i] = false;
}

// Depth-Frist Search
void DFS(int start, bool visited[], vector<int> graph[])
{
	visited[start] = true; // 방문 표시
	cout << start << " ";
	for (int i = 0 ; i < graph[start].size() ; i++)
	{
		int next = graph[start][i]; // 현재 노드에 연결된 노드를 가져옴
		if (visited[next] != true) // 방문되지 않았다면
			DFS(next, visited, graph); // 방문
	}
}

// Breadth-First Search
void BFS(int start, bool visited[], vector<int> graph[])
{
	queue<int> que;

	que.push(start);
	visited[start] = true;
	while (!que.empty())
	{
		int front = que.front();
		cout << front << " ";
		que.pop();
		for (int i = 0 ; i < graph[front].size() ; i++)
		{
			int next = graph[front][i];
			if (visited[next] != true)
			{
				que.push(next);
				visited[next] = true;
			}
		}
	}
}

int main(void)
{
	cin >> N >> M >> V;
	vector<int> graph[N + 1]; // 그래프 간선을 표현
	bool visited[N + 1]; // 방문했는지 여부를 확인할 배열

	reset(visited);
	for (int i = 0 ; i < M ; i++)
	{
		int a, b;

		cin >> a >> b;
		graph[a].push_back(b); // 간선 연결
		graph[b].push_back(a); // 간선 연결
	}
	for (int i = 1 ; i <= N ; i++) // 정렬
		sort(graph[i].begin(), graph[i].end());

	// 그래프 출력	
	// for (int i = 1 ; i <= N ; i++)
	// {
	// 	cout << "graph[" << i << "] : ";
	// 	for (int j = 0; j < graph[i].size() ; j++)
	// 		cout << graph[i][j] << " ";
	// 	cout << "\n";
	// }

	DFS(V, visited, graph);
	reset(visited);
	cout << "\n";
	BFS(V, visited, graph);
	cout << "\n";
}
