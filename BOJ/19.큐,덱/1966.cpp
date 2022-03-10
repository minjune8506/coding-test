/**
 * 1966 : 프린터 큐
 *
 * 프린터 기기는 인쇄하고자 하는 문서를 인쇄 명령을 받은 순서대로,
 * 즉 먼저 요청된 것을 먼저 인쇄한다.
 * 여러 개의 문서가 쌓이면 Queue 자료구조에 쌓여 FIFO에 따라 인쇄가 된다.
 * 1. 현재 Queue의 가장 앞에 있는 문서의 중요도를 확인
 * 2. 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 있다면, 이 문서를 인쇄하지 않고
 * Queue의 가장 뒤에 재배치 한다. 그렇지 않으면 바로 인쇄를 한다.
 * 현재 Queue에 있는 문서의 수와 중요도가 주어졌을 떄, 어떤 한 문서가 몇번쨰로
 * 인쇄되는지 알아내는 것이다.
 *
 * 입력
 * 문서의 개수 N (1 <= N <= 100)과, 몇 번째로 인쇄되었는지 궁금한 문서가
 * 현재 Queue에서 몇 번째에 놓여있는지를 나타내는 정수 M (0 <= M < N)이 주어진다.
 * 맨 왼쪽은 0번째라고 한다.
 * 두번째 줄에는 N개 문서의 중요도가 차례대로 주어진다. 중요도는 1이상 9 이하의 정수이고,
 * 중요도가 같은 문서가 여러개 있을 수 있다.
 *
 * 출력
 * 문서가 몇 번째로 인쇄되는지 출력한다.
 */
/**
 * 풀이
 * 
 * priority_queue를 이용하여, 우선순위를 저장한다. (큰 순서대로 나올 수 있게)
 * queue의 맨 앞에 있는 작업의 우선순위가 priority_queue의 top의 우선순위와 같다면(우선순위가 제일 높다면)
 * 목표하는 작업 번호 (M)과 같은지 비교하여
 * 같다면 => printCount 출력 후 종료
 * 같지 않다 => queue, priority_queue의 맨 앞 작업 제거 후 printCount 증가
 * 우선순위가 같지 않다면 -> 큐 회전
 */
#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int testCase;

	cin >> testCase;
	for (int i = 0 ; i < testCase ; i++)
	{
		queue<pair<int, int> > jobs;
		priority_queue<int> maxHeap;
		int N, M;
		int printCount = 1;

		cin >> N >> M;
		for (int i = 0 ; i < N; i++)
		{
			int value;
			
			cin >> value;
			maxHeap.push(value);
			jobs.push(make_pair(i, value));
		}
		while (!jobs.empty())
		{
			pair<int, int> temp;
			
			temp = jobs.front();
			if (temp.second == maxHeap.top())
			{
				if (temp.first == M)
				{
					cout << printCount << "\n";
					break ;
				}
				else
				{
					jobs.pop();
					maxHeap.pop();
					printCount++;
				}
			}
			else
			{
				jobs.pop();
				jobs.push(temp);
			}
		}
	}
}
