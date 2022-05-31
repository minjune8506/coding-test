#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int	main(void)
{
	string a;
	string b;

	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for (int i = 0 ; i < a.length() ; i++)
	{
		if (a[i] > b[i])
		{
			cout << a << endl;
			return 0;
		}
		else if (a[i] < b[i])
		{
			cout << b << endl;
			return 0;
		}
	}
}
