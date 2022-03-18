/**
 * 2751 : 수 정렬하기 2
 * 
 * 시간제한 : 2초 (nlogn의 시간복잡도로 풀 수 있음)
 * N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
 * 
 * 입력
 * 첫째 줄에 수의 개수 N (1 <= N <= 1,000,000)이 주어진다.
 * 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다.
 * 수는 중복되지 않는다.
 * 
 * 출력
 * 첫째 줄부터 N개의 줄에 오른차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int N;

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	vector<int> nums;

	for (int i = 0 ; i < N ; i++)
	{
		int num;

		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());
	for (int i = 0 ; i < N ; i++)
		cout << nums[i] << "\n";
}
