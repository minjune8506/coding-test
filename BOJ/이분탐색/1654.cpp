/**
 * 1654 : 이분 탐색
 * 
 * 시간 제한 : 2초
 * N개의 랜선을 만들어야 한다.
 * K개의 길이가 제각각인 랜선을 가지고 있다.
 * 랜선을 모두 N개의 같은 길이로 만들고 싶다 -> K개의 랜선을 잘라서 만든다.
 * ex) 300cm -> 140cm 두 개를 잘라내면 20cm는 버려야 한다.
 * 랜선을 자르거나 만들 때 손실되는 길이는 없다고 가정한다.
 * K개의 랜선으로 N개의 랜선을 만들 수 없는 경우는 없다고 가정한다.
 * 자를 때는 항상 센티미터 단위의 정수길이만큼 자른다고 가정한다.
 * N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다.
 * 이때 만들 수 있는 최대 랜선의 길이를 구하라
 * 
 * 입력
 * 이미 가지고 있는 랜선의 개수 K, 필요한 랜선의 개수 N이 입력된다.
 * K는 1이상 10,000이하의 정수이고 N은 1이상 1,000,000이하의 정수이다
 * 항상 K <= N 이다.
 * K줄에 걸쳐 이미 가지고 있는 각 랜선의 길이가 센티미터 단위의 정수로 입력된다.
 * 랜선의 길이는 2^31 - 1보다 작거나 같은 자연수이다.
 * 
 * 출력
 * N개를 만들 수 있는 랜선의 최대 길이를 센티미터 단위의 정수로 출력
 */
// 입력으로 주어진 랜선을 잘라서 최대의 크기를 만들어야 한다.
// 어떻게 각자 랜선에서 최대로 나눌수 있을까?
// Brute-Force가 제일 먼저 떠오름
// 랜선의 길이를 일단 정해놓고 늘려나가면서 나눠서 11개가 맞으면 탈출 -> 시간초과
// 이분탐색을 어떻게 이용할 수 있는가?
// 최대 길이부터 시도 -> 나눠진 개수가 너무 작다 -> 반으로 나눈다
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, K;

void binarySearch(vector<int> &lines, int max)
{
	int start = 0;
	int end = max;
	int m;
	int count;
	while (end - start > 0)
	{
		m = (start + end) / 2;
		count = 0;
		for (int i = 0 ; i < lines.size() ; i++)
			count += lines[i] / m;
		cout << "m : " << m << endl;
		cout << "count : " << count << endl;
		if (count > K)
			end = m - 1;
		else
			start = m;
	}
	cout << end << '\n';
}

int main(void)
{
	cin >> N >> K;
	vector<int> lines;
	int max = -1;

	for (int i = 0 ; i < N ; i++)
	{
		int length;

		cin >> length;
		if (length > max)
			max = length;
		lines.push_back(length);
	}
	cout << "max : " << max << '\n';
	binarySearch(lines, max);
}
