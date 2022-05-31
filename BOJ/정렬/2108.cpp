/**
 * 2108 : 통계학
 * 
 * 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다.
 * 단 N은 홀수라고 하자.
 * 1. 산술평균 : N개의 수들의 합을 N으로 나눈 값
 * 2. 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
 * 3. 최빈값 : N개의 수들 중 가장 많이 나타나는 값
 * 4. 범위 : N개의 수들 중 최댓값과 최솟값의 차이
 * N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성해라.
 * 
 * 입력
 * N (1 <= N <= 500,000)이 주어진다.
 * N은 홀수이다.
 * N개의 줄에 정수가 주어진다. 정수들의 절대값은 4000을 넘지 않는다.
 * 
 * 출력
 * 산술평균 : 소수점 이하 첫째자리에서 반올림한 값을 출력한다.
 * 중앙값
 * 최빈값 : 여러 개인 경우, 최빈값 중 두 번째로 작은 값을 출력한다.
 * 범위를 출력
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef struct s_key {
	int	key;
	int count;
}t_key;

using namespace std;

int N;

int	comp(t_key a, t_key b)
{
	if (a.count > b.count)
		return true;
	else if (a.count == b.count)
	{
		if (b.key > a.key)
			return true;
	}
	return false;
}

int printMode(vector<int> numbers)
{
	vector<t_key> keys;

	for (int i = N - 1 ; i >= 0 ; i--)
	{
		t_key temp;
		int count = 0;

		temp.key = numbers[i];
		while (numbers[i] == numbers[i - 1])
		{
			count++;
			i--;
			if (i < 0)
				break ;
		}
		temp.count = count;
		keys.push_back(temp);
	}
	
	sort(keys.begin(), keys.end(), comp);

	if (keys.size() > 1)
	{
		if (keys[0].count == keys[1].count)
			cout << keys[1].key << "\n";
		else
			cout << keys[0].key << "\n";
	}
	else
		cout << keys[0].key << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<int> numbers;
	double sum = 0;

	for (int i = 0 ; i < N ; i++)
	{
		int num;

		cin >> num;
		sum += num;
		numbers.push_back(num);
	}

	// Average
	cout << (int)round(sum / N) << "\n";

	// Sort
	sort(numbers.begin(), numbers.end());
	
	// Median Value
	cout << numbers[N / 2] << "\n";

	// Mode
	printMode(numbers);

	// Range
	cout << numbers[N - 1] - numbers[0] << "\n";
}
