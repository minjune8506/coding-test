/**
 * @file 1043.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 거짓말
 * @date 2023-04-16
 *
 * 사람의 수 N / 파티의 수 M
 * 진실을 아는 사람의 수 / 진실을 아는 사람
 * 각 파티의 인원수 / 각 파티에 오는 사람
 *
 * 거짓말쟁이로 알려지지 않으면서 과장된 이야기를 할 수 있는
 * 파티 개수의 최댓값
 *
 * 1 <= N <= 50
 * 0 <= M <= 50
 *
 * 거짓말 가능한 경우
 *
 * 현재 파티에 진실을 아는 사람이 없는 경우
 * +
 * 현재 파티의 참가자들이 진실을 아는 사람이 있는 파티에 안오는 경우
 *
 * GG....
 * 유니온 파인드 알고리즘
 */
#include <iostream>
#include <vector>

int N, M;
int knowTruth;
int parent[51];

std::vector<int> know;
std::vector<int> participants[51];

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return;
	}
	parent[x] = y;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> N >> M >> knowTruth;
	for (int i = 0; i < knowTruth; i++) {
		int number;
		std::cin >> number;
		know.push_back(number);
	}

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int entry;
		std::cin >> entry;
		int num;
		int prev;
		for (int j = 0; j < entry; j++) {
			if (j >= 1) {
				prev = num;
				std::cin >> num;
				merge(num, prev);
			} else {
				std::cin >> num;
			}
			participants[i].push_back(num);
		}
	}

	int count = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < participants[i].size(); i++) {
			int x = find(participants[i][j]);
			bool canGo = true;
			for (int k = 0; k < know.size(); k++) {
				if (find(x) == find(know[k])) {
					canGo = false;
					break;
				}
			}
			if (canGo) {
				count++;
			}
		}
	}
	std::cout << count << '\n';
}
