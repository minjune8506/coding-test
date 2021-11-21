#include <iostream>

using namespace std;

int	main(void)
{
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;

	cin >> n;
	for (int i = 1; i <= n; i++)
		cout << i << "\n";
}
