/**
 * 1874 : 스택 수열
 * 
 * 1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어넣음으로써,
 * 하나의 수열을 만들 수 있다.
 * 이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 하자
 * 임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지,
 * 있다면 어떤 순서로 push와 pop을 수행해야 하는지를 알아낼 수 있다.
 * 이를 계산하는 프로그램을 작성해라.
 * 
 * 입력
 * 첫 줄에 n (1 <= n <= 100,000)이 주어진다.
 * 둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 정수가 하나씩 순서대로 주어진다.
 * 물론 같은 정수가 두 번 나오는 일은 없다.
 * 
 * 출력
 * 필요한 연산을 한 줄에 하나씩 출력한다.
 * push는 +로, pop은 -로 표현한다.
 * 불가능한 경우 NO를 출력한다.
 */
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<int> target;
	vector<char> answer;
	stack<int> s;

	for (int i = 0 ; i < N ; i++)
	{
		int temp;

		cin >> temp;
		target.push_back(temp);
	}
	int index = 0;
	for (int i = 0; i < N; i++)
	{
		s.push(i + 1);
		answer.push_back('+');
		while (s.top() == target[index])
		{
			s.pop();
			answer.push_back('-');
			index++;
			if (index == target.size() || !s.size())
				break ;
		}
	}
	if (s.size())
		cout << "NO" << "\n";
	else
		for (int i = 0 ; i < answer.size() ; i++)
			cout << answer[i] << "\n";
}
