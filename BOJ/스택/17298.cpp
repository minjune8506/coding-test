/**
 * 17298 : 오큰수
 * 
 * 시간제한 1초
 * 
 * 크기가 N인 수열 A = A1, A2, ..., An이 있다.
 * 수열의 각 원소 Ai에 대해 오큰수 NGE(i)를 구하려고 한다.
 * Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수중에서 가장 왼쪽에 있는 수를 말한다.
 * 그러한 수가 없는 경우에 오큰수는 -1이다.
 * 
 * A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(3) = 7, NGE(4) = -1이다.
 * A = [9, 5, 4, 8]인 경우  NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.
 * 
 * 입력
 * 첫째 줄에 수열 A의 크기 N(1 <= N <= 1,000,000)이 주어진다.
 * 둘쨰 줄에 수열 A의 원소 A1, A2, ..., An (1 <= Ai <= 1,000,000)이 주어진다.
 * 
 * 출력
 * 총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 구분해 출력한다.
 */
#include <iostream>
#include <stack>

using namespace std;

int N;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	stack<int> s1;
	stack<int> s2;
	stack<int> answer;

	for (int i = 0 ; i < N ; i++)
	{
		int num;

		cin >> num;
		s1.push(num);
	}

	while (!s1.empty())
	{
		if (s2.empty()) 
			answer.push(-1);
		else if (s1.top() < s2.top()) // s2의 맨 위의 원소가 더 큰 경우
		 	answer.push(s2.top());
		else
		{
			while (s1.top() >= s2.top()) // s1의 맨위의 원소가 더 클 동안
			{
				s2.pop(); // s2 pop
				if (s2.empty())
				{
					answer.push(-1);
					break ;
				}
			}
			if (!s2.empty())
				answer.push(s2.top());
		}
		s2.push(s1.top());
		s1.pop();
	}
	
	while (!answer.empty())
	{
		cout << answer.top() << " ";
		answer.pop();
	}
	cout << "\n";
}
