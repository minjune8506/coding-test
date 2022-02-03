/* 2346 : 풍선 터뜨리기
 *
 * 1번부터 N번까지 N개의 풍선이 원형으로 놓여있고, i번 풍선의 오른쪽에는 i + 1번 풍선이 있고, 왼쪽에는 i - 1번
 * 풍선이 있다. 단 1번의 왼쪽에 N번 풍선이, N번 풍선의 오른쪽에는 1번 풍선이 있따.
 * 각 풍선 안에는 종이가 하나 있고, -N보다 크거나 같고, N보다 작거나 같은 정수가 적혀있다.
 * 제일 처음에 1번 풍선을 터뜨린다. 다음에 종이에 적혀있는 값만큼 이동해 풍선을 터뜨린다.
 * 양수 => 오른쪽, 음수 => 왼쪽
 * 이미 터진 풍선은 빼고 이동한다. (세지 않는다)
 * 
 * 입력 : 자연수 N (1 <= N <= 1000)이 주어진다.
 * 다음줄에는 각 풍선안의 종이에 적혀 있는 수가 주어진다. 0은 적혀있지 않다.
 * 
 * 출력 : 첫째 줄에 터진 풍선의 번호를 차례로 나열한다.
*/
#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int n;
deque< pair<int, int> > dq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0 ; i < n ; i++)
	{
		int temp;
		cin >> temp;
		dq.push_back(make_pair(temp, i + 1));
	} // 종이에 적혀있는수, 풍선 번호
	while (true)
	{
		int temp;
		
		temp = dq.front().first;
		cout << dq.front().second << " ";
		dq.pop_front();
		if (temp > 0)
		{
			for (int i = 0 ; i < temp - 1 ; i++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else
		{
			for (int i = 0 ; i < -1 * temp ; i++)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
		if (dq.empty())
			break ;
	}
	cout << "\n";
}
