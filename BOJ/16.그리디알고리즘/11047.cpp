/**
 * 11047 : 동전 0
 * 
 * 시간제한 : 1초
 * 가지고 있는 동전은 총 N종류이고, 각각의 동전을 많이 가지고 있다.
 * 동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다.
 * 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.
 * 
 * 입력
 * N과 K (1<= N <= 10, 1 <= K <= 100,000,000)
 * N개의 줄에 동전의 가치 Aj가 오름차순으로 주어진다.
 * (1 <= Ai <= 1,000,000, A1 = 1, i >= 2인 경우에 Ai는 Ai-1의 배수)
 * 
 * 출력
 * K원을 만드는데 필요한 동전 개수의 최솟값
 */

/**
 * 그리디 알고리즘을 사용해도 최적해를 구할 수 있는가? => yes
 * 가장 값이 큰 동전을 최대로 사용 한 후, 그 다음으로 값이 큰 동전을 사용. 반복
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> coins;
	int N, K;
	int count = 0;
	int i = 0;
	
	cin >> N >> K;
	for (int i = 0 ; i < N ; i++)
	{
		int coin;

		cin >> coin;
		coins.push_back(coin);
	}
	sort(coins.begin(), coins.end(), greater<int>());
	while (K > 0)
	{
		count += K / coins[i];
		K %= coins[i++];
	}
	cout << count << "\n";
}
