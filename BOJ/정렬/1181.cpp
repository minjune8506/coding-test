/**
 * 1181 : 단어 정렬
 * 
 * 시간제한 : 2초
 * 알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라
 * 정렬하는 프로그램을 작성하시오.
 * 1. 길이가 짧은 것부터
 * 2. 길이가 같으면 사전 순으로
 * 
 * 입력
 * 첫째 줄에 단어의 개수 N이 주어진다. (1 <= N <= 20,000)
 * 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다.
 * 주어지는 문자열의 길이는 50을 넘지 않는다.
 * 
 * 출력
 * 조건에 따라 정렬하여 단어들을 출력한다.
 * 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct s_word
{
	int length;
	string word;
}t_word;

int N;

bool comp(t_word a, t_word b)
{
	if (a.length == b.length)
		return a.word < b.word;
	return a.length < b.length;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<t_word> words;

	for (int i = 0 ; i < N ; i++)
	{
		t_word temp;

		cin >> temp.word;
		temp.length = temp.word.length();
		words.push_back(temp);
	}
	sort(words.begin(), words.end(), comp);
	for (int i = 0 ; i < words.size(); i++)
	{
		if (i > 0 && words[i].word == words[i - 1].word)
			continue;
		cout << words[i].word << '\n';
	}
}
