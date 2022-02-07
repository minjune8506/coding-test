#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	queue<int> que;

	for (int i = 0 ; i < 5 ; i++)
		que.push(i);
	
	int front = que.front();
	cout << "front : " << front << "\n";
	int back = que.back();
	cout << "back : " << back << "\n";

	while (!que.empty())
	{
		cout << que.front() << " ";
		que.pop();
	}
	cout << endl;
}
