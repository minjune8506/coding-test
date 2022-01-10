#include <iostream>

using namespace std;

void	print_star(int n)
{
	if (n == 3)
		cout << "***\n" <<"* *\n" << "***\n";
	print_star(n / 3);
}

int	main(void)
{
	int N;

	cin >> N;
	
}
