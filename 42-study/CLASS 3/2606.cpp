/**
 * @file 2606.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 바이러스
 * @date 2023-02-24
 *
 * 한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에
 * 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸린다.
 *
 * 1번 컴퓨터가 웜 바이러스에 걸렸을 때 1번 컴퓨터를 통해
 * 웜 바이러스에 걸리게 되는 컴퓨터 수를 구해라
 *
 * 컴퓨터 수 <= 100 번호는 1번부터 시작
 *
 * - DFS 이용
 */
#include <cstring>
#include <iostream>
#include <vector>

void dfs(std::vector<int> networks[], int current, bool visited[]) {
	visited[current] = true;
	for (int i = 0; i < networks[current].size(); i++) {
		if (!visited[networks[current][i]]) {
			dfs(networks, networks[current][i], visited);
		}
	}
}

int main(void) {
	int computer, links;

	std::cin >> computer >> links;
	std::vector<int> networks[computer + 1];

	for (int i = 0; i < links; i++) {
		int startComputer, endComputer;
		std::cin >> startComputer >> endComputer;
		networks[startComputer].push_back(endComputer);
		networks[endComputer].push_back(startComputer);
	}

	bool visited[computer + 1];
	int count = 0;
	memset(visited, false, computer + 1);

	dfs(networks, 1, visited);

	for (int i = 2; i < computer + 1; i++) {
		if (visited[i]) {
			count++;
		}
	}
	std::cout << count << std::endl;
}
