#include <iostream>
#include <algorithm>

using namespace std;

void print(int arr[])
{
	cout << "arr[i] : " ;
	for (int i = 0 ; i < 10 ; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(void)
{
	int arr[10] = {3, 7, 2, 4, 1, 0, 9, 8, 5, 6};
	
	print(arr);
	sort(arr, arr + 10);
	print(arr);
	return (0);
}
