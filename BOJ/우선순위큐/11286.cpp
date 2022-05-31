/**
 * 11286 : 절대값 힙
 * 
 * 1. 배열에 정수 x (x != 0)를 넣는다.
 * 2. 배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
 * 절대값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고,
 * 그 값을 배열에서 제거한다.
 * 프로그램은 처음에 비어있는 배열에서 시작하게 된다.
 * 
 * 입력
 * 연산의 개수 N(1<=N<=100,000)이 주어진다. 다음 N개의 줄에는 연산에 대한
 * 정보를 나타내는 정수 x가 주어진다. 만약 x가 0이 아니라면 배열에 x라는 값을 추가하는 연산이고,
 * x가 0이라면 배열에서 절댓값이 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우이다.
 * 입력되는 정수는 -2^31보다 크고, 2^31보다 작다.
 * 
 * 출력
 * 입력에서 0이 주어진 횟수만큼 답을 출력한다.
 * 배열이 비어있는 경우인데 절대값이 가장 작은 값을 출력하라고 한경우 0을 출력
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class comp {
	public:
		bool operator()(const int &lhs, const int &rhs)const {
			if (abs(lhs) == abs(rhs))
				return lhs > rhs; // 절대값이 같다면 더 작은 데이터가 루트 노드
			return (abs(lhs) > abs(rhs)); // 절대값이 작은 데이터가 루트 노드
		}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, comp> que;
	int n;

	cin >> n;
	for (int i = 0 ; i < n ; i++)
	{
		int x;

		cin >> x;
		if (x != 0)
			que.push(x);
		else
		{
			if (que.empty())
				cout << 0 << "\n";
			else
			{
				cout << que.top() << "\n";
				que.pop();
			}
		}
	}
}
