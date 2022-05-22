#include <iostream>

using namespace std;

void lowerBound(int *ary, int size, int key)
{
	int start = 0;
	int end = size;
	int mid;
	while (end - start > 0)
	{
		mid = (start + end) / 2;
		if (ary[mid] < key)
			start = mid + 1;
		else
			end = mid ;
	}
	cout << end + 1 << '\n';
}

void upperBound(int *ary, int size, int key)
{
	int start = 0;
	int end = size;
	int mid;
	while (end - start > 0)
	{
		mid = (start + end) / 2;
		if (ary[mid] <= key)
			start = mid + 1;
		else
			end = mid;
	}
	cout << end + 1 << endl;
}

int main(void)
{
	int ary[] = {1, 2, 3, 3, 3, 4, 5, 5};
	cout << *lower_bound(ary, ary + 8, 3) << endl;
	lowerBound(ary, 8, 3);
	upperBound(ary, 8, 3);
}
