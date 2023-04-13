/**
 * @file 15686.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 치킨 배달
 * @date 2023-04-12
 *
 * 크기가 NxN인 도시
 * 도시의 각 칸은 빈 칸 / 치킨집 / 집 중 하나
 * 도시의 칸은 (r, c) 형태 r, c는 1부터 시작
 *
 * 치킨 거리 : 집과 가장 가까운 치킨집 사이의 거리
 * 도시의 치킨 거리 -> 모든 집의 치킨 거리의 합
 *
 * (r1, c1) (r2, c2) 거리 => |r1-r2| + |c1-c2|
 *
 * 도시의 치킨집 중에서 최대 M개를 고르고
 * 나머지 치킨집을 모두 없앤다.
 *
 * 도시의 치킨거리가 가장 작게 만들어라
 *
 * - 치킨집 4개 N: 2 인경우
 * - 4 C 2 의 경우의수
 * - 각 경우에 대해서 치킨 거리 구하기
 */
#include <climits>
#include <iostream>
#include <vector>

int N, M;
std::vector<std::pair<int, int> > chickens;
std::vector<std::pair<int, int> > houses;

std::pair<int, int> picked[13];
bool visited[13];

int min = INT_MAX;

void calculate() {
	int sum = 0;
	for (auto house : houses) {
		int min_distance = INT_MAX;
		for (int i = 0; i < M; i++) {
			int distance = std::abs(house.first - picked[i].first) +
						   std::abs(house.second - picked[i].second);
			if (min_distance > distance) {
				min_distance = distance;
			}
		}
		sum += min_distance;
	}
	if (min > sum) {
		min = sum;
	}
}

void pick(int cnt, int curr) {
	if (cnt == M) {
		calculate();
		return;
	}

	for (int i = curr; i < chickens.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			picked[cnt] = chickens[i];
			pick(cnt + 1, i);
			visited[i] = false;
		}
	}
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int number;

			std::cin >> number;
			if (number == 1) {
				houses.push_back(std::make_pair(i, j));
			}
			if (number == 2) {
				chickens.push_back(std::make_pair(i, j));
			}
		}
	}

	pick(0, 0);

	std::cout << min << '\n';
}
