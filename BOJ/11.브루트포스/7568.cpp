/**
 * 7568 : 덩치
 * 
 * 시간제한 : 1초
 * 사람의 덩치를 키와 몸무게, 두 개의 값으로 표현하여 등수를 매겨보려고 한다.
 * 몸무게가 xkg이고 키가 ycm 이면 이 사람의 덩치는 (x, y)로 표시된다.
 * 두 사람 A와 B의 덩치가 각각 (x,y) (p,q)라고 할때
 * x > p and y > q이라면 우리는 A의 덩치가 B의 덩치보다 더 크다 라고 말한다.
 * N명의 집단에서 각 사람의 덩치 등수는 자신보다 더 큰 덩치의 사람의 수로 정해진다.
 * 만일 자신보다 더 큰 덩치의 사람이 k명이라면 그 사람의 덩치 등수는 k + 1이 된다.
 * 이렇게 등수를 정하면 같은 덩치 등수를 가진 사람은 여러명도 가능하다.
 * 
 * 입력
 * 첫 줄에는 전체 사람의 수 N이 주어진다.
 * 그리고 이어지는 N개의 줄에는 각 사람의 몸무게와 키를 나타내는 양의 정수
 * x와 y가 하나의 공백을 두고 각각 나타난다.
 * 2 <= N <= 50
 * 10 <= x, y <= 200
 * 
 * 출력
 * 입력에 나열된 사람의 덩치 등수를 구해서 그 순서대로 첫 줄에 출력해야 한다.
 * 단, 각 덩치 등수는 공백 문자로 분리되어야 한다.
 */ 
#include <iostream>
#include <vector>

typedef struct s_info
{
	int weight;
	int height;
}t_info;

using namespace std;

int N;

void getRank(vector<t_info> info, t_info target)
{
	int count = 0;

	for (int i = 0 ; i < info.size() ; i++)
	{
		if (info[i].height > target.height && info[i].weight > target.weight)
			count++;
	}
	cout << count + 1 << " ";
}

int main(void)
{
	cin >> N;
	vector<t_info> info;
	for (int i = 0 ; i < N ; i++)
	{
		t_info temp;

		cin >> temp.weight;
		cin >> temp.height;
		info.push_back(temp);
	}
	for (int i = 0 ; i < N ; i++)
		getRank(info, info[i]);
	cout << "\n";
}
