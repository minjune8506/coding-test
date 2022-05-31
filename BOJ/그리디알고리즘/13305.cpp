/**
 * 13305 : 주유소
 * 
 * N개의 도시가 일직선 도로 위에 있다.
 * 제일 왼쪽의 도시에서 제일 오른쪽의 도시로 자동차를 이용하여 이동하려고 한다.
 * 인접한 두 도시 사이의 도로들은 서로 길이가 다를 수 있고, 단위는 KM이다.
 * 처음 출발시 주유소에서 기름을 넣고 출발하여야 한다.
 * 기름통의 크기는 무제한이며, 도로를 이용하여 이동할 떄 1km마다 1리터의 기름을 사용한다.
 * 각 도시에는 하나의 주유소만 있고, 도시마다 주유소의 리터당 가격은 다를 수 있다.
 * 가격의 단위 : 원
 * 각 도시에 있는 주유소의 기름 가격과, 도로의 길이를 입력으로 받아, 제일 왼쪽의 도시에서
 * 제일 오른쪽의 도시까지 이동하는 최소의 비용을 계산하는 프로그램을 작성
 * 
 * 입력
 * 도시의 개수를 나타내는 정수 N (2 <= N <= 100,000)이 주어진다.
 * 인접한 두 도시를 연결하는 도로의 길이가 왼쪽부터 N - 1개의 자연수로 주어진다.
 * 총 거리는 1 <= <= 10억 이하의 자연수이다.
 * 리터당 가격 또한 1 <= <= 10억 이하의 자연수이다.
 * 
 * 출력
 * 제일 왼쪽 도시에서 제일 오른쪽 도시로 가는 최소 비용을 출력
 */

/**
 * 처음에는 무조건 기름을 넣어야 출발 할 수 있다.
 */
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N;

	cin >> N;
	vector<int> length;
	vector<int> gas;
	unsigned long long cost = 0;
	int min = 0;

	for (int i = 0 ; i < N - 1 ; i++)
	{
		int road;

		cin >> road;
		length.push_back(road);
	}
	for (int i = 0 ; i < N - 1 ; i++)
	{
		int price;

		cin >> price;
		gas.push_back(price);
	}
	for (int i = 0 ; i < gas.size() ; i++)
	{
		if (!cost)
			min = gas[i];
		if (min > gas[i])
			min = gas[i];
		cost += (long long)min * length[i];
	}
	cout << cost << "\n";
}
