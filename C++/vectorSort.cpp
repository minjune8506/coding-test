#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void print(vector<int> v)
{
	cout << "vector : " ;
	for (int i = 0 ; i < v.size() ; i++)
		cout << v[i] << " ";
	cout << endl;
}

int main(void)
{
	// 난수 생성을 위해
	srand((int)time(NULL));

	vector<int> v;
	int n = 10;

	for (int i = 0 ; i < n ; i++)
		v.push_back(rand() % 10); // vector에 난수 삽입
	print(v); // 정렬 전
	sort(v.begin(), v.end(), greater<int>()); // [begin, end) 내림차순 정렬
	print(v); // 정렬 후

	return (0);
}
