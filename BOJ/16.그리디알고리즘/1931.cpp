/**
 * 1931 : 회의실 배정
 * 
 * 한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의에 대해 회의실 사용표를 만드려고 한다.
 * 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수를 찾아보자.
 * 회의는 한번 시작하면 중간에 중단될 수 없고, 한 회의가 끝나는 것 과 동시에 다음 회의가 시작 가능하다.
 * 회의의 시작시간과 끝나는 시간이 같을 수도 있다.
 * 
 * 입력
 * 회의의 수 N (1 <= N <= 100,000)이 주어진다.
 * 2 ~ N + 1 줄까지 각 회의의 정보가 주어지는데 공백을 사이에 두고
 * 시작시간 끝나는 시간이 주어진다.
 * 시작시간과 끝나는 시간은 2^31 - 1보다 작거나 같은 자연수 또는 0이다.
 * 
 * 출력
 * 최대 사용할 수 있는 회의의 최대 개수를 출력한다.
 */
/**
 * 풀이
 * 회의 시간을 입력을 받아서 끝나는 시간을 기준으로 정렬을 수행한다.
 * 끝나는 시간이 같을 경우 회의 시작 시간을 기준으로 오름차순으로 정렬한다.
 * 왜 그리디 알고리즘을 사용할 수 있을까?
 * 시작 시간이 빨라도 회의가 늦게 끝나면 최대 회의 수를 구할 수 없다.
 * -> 끝나는 시간을 기준으로 빨리 끝나는 순으로 정렬해야 한다.
 * 예) 1 2, 2 2 라는 회의 시간이 있다면 1 -> 2 / 2 -> 2 순으로 회의실을 사용할 수 있으므로
 * 끝나는 시간이 같을 경우 시작 시간이 빠른 순으로 정렬을 수행한다.
 * 처음부터 끝나는 시간이 가장 빠른 회의를 계속해서 고른다면 최대 회의 수를 구할 수 있으므로
 * 그리디 알고리즘을 사용 가능한다.
 */

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int N;

typedef struct meeting
{
	int start;
	int end;
} meeting;

bool compare(meeting a, meeting b)
{
	if (a.end == b.end)
		return a.start < b.start;
	return a.end < b.end;
}

int main(void)
{
	vector<meeting> meet;
	int count = 0;
	int curr_end = -1;
	
	cin >> N;
	for (int i = 0 ; i < N ; i++)
	{
		meeting m;

		cin >> m.start >> m.end;
		meet.push_back(m);
	}
	sort(meet.begin(), meet.end(), compare);
	for (int i = 0 ; i < meet.size() ; i++)
	{
		if (curr_end == -1 || meet[i].start >= curr_end)
		{
			curr_end = meet[i].end;
			count++;
		}
	}
	cout << count << "\n";
}
