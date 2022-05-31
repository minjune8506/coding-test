#include <iostream>
#include <stack>

using namespace std;

int	main(void)
{
	int K;
	int num;
	int sum = 0;
	stack<int> s;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> K;
	while (K > 0)
	{
		cin >> num;
		if (num)
			s.push(num);
		else
			s.pop();		
		K--;
	}
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	cout << sum << "\n";
}
