/**
 * 11651 : 좌표 정렬하기 2
 * 
 * 2차원 평면 위의 점 N개가 주어진다. 좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순으로
 * 정렬한 다음 출력하는 프로그램을 작성하시오.
 * 
 * 입력
 * 첫째 줄에 점의 개수 N (1 <= N <= 100,000)이 주어진다.
 * 둘째 줄부터 N개의 줄에는 i번점의 위치 xj와 yj가 주어진다. (-100,000 <= xj, yj <= 100,000)
 * 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.
 * 
 * 출력
 * 첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.
 */
#include <iostream>
#include <vector>
#include <algorithm>

typedef struct s_point {
	int x;
	int y;
}t_point;

using namespace std;

int N;

bool comp(t_point a, t_point b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<t_point> points;

	for (int i = 0 ; i < N ; i++)
	{
		t_point temp;
		
		cin >> temp.x >> temp.y;
		points.push_back(temp);
	}
	sort(points.begin(), points.end(), comp);
	for (int i = 0 ; i < N ; i++)
		cout << points[i].x << ' ' << points[i].y << '\n';
}
