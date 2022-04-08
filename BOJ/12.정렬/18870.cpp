/**
 * 18870 : 좌표 얍축
 * 
 * 시간 제한 : 2초
 * 수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다.
 * 이 좌표에 압축을적용하려고 한다.
 * Xi 좌표 압축 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의
 * 개수와 같아야 한다.
 * X1, X2, ... , XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N을 출력
 * 
 * 입력 
 * 첫째 줄에 N이 주어진다.
 * 둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.
 * (1 <= N <= 1,000,000)
 * -10^9 <= Xi <= 10^9
 * 
 * 출력
 * 첫째 줄에 X'1, X'2, ..., X'N을 공백 한칸으로 구분해서 출력
 */
// 정렬, 중복값 제거 후 원래의 좌표가 몇번째인지 찾는과정 -> O(n)으로 하면 시간초과
// O(NlogN)으로 해야 풀린다. -> 이진탐색 or lower_bound

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<int> points;
	vector<int> original;

	for (int i = 0 ; i < N ; i++)
	{
		int point;

		cin >> point;
		points.push_back(point);
		original.push_back(point);
	}
	sort(points.begin(), points.end());
	points.erase(unique(points.begin(), points.end()), points.end());
	vector<int>::iterator iter;
	for (int i = 0 ; i < original.size() ; i++)
	{
		auto it = lower_bound(points.begin(), points.end(), original[i]);
		cout << it - points.begin() << ' ';
	}
	cout << '\n';
}
