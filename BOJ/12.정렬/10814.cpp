/**
 * 10814 : 나이순 정렬
 * 
 * 시간 제한 : 3초
 * 온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주진다.
 * 이때, 회원들을 나이가 증가하는 순으로, 나가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는
 * 프로그램을 작성하시오.
 * 
 * 입력
 * 첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 <= N <= 100,000)
 * 둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다.
 * 나이는 1보다 크거나 같으며, 200보다 작거나 같은 정수이고,
 * 이름은 알파벳 대소문자로 이루어져 있고, 길이가 100보다 작거나 같은 문자열이다.
 * 입력은 가입한 순서로 주어진다.
 * 
 * 출력
 * 첫째 줄부터 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순, 나이가 같으면 가입한 순으로
 * 한 줄에 한 명씩 나이와 이름을 공백으로 구분해 출력한다.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct s_member
{
	int id;
	int age;
	string name;
}t_member;

int N;

bool comp(t_member a, t_member b)
{
	if (a.age == b.age)
		return a.id < b.id;
	return a.age < b.age;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<t_member> members;

	cin >> N;
	for (int i = 0 ; i < N ; i++)
	{
		t_member temp;

		cin >> temp.age >> temp.name;
		temp.id = i;
		members.push_back(temp);
	}
	sort(members.begin(), members.end(), comp);
	// stable_sort 함수를 써도 된다.
	for (int i = 0 ; i < N ; i++)
		cout << members[i].age << ' ' << members[i].name << '\n';
}

