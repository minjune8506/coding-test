/**
 * 9251 : LCS
 * 
 * LCS (Longest Common Subsequence, 최장 공통 부분 수열) 구하기
 * 
 * 입력 : 알파벳 대문자로만 이루어져 있으며, 최대 1000글자
 * 출력 : 입력으로 주어진 두 문자열의 LCS 길이 출력
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int table[1001][1001] = {0, };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string a, b;

	cin >> a >> b;
	int a_size = a.length();
	int b_size = b.length();
	for (int i = 1 ; i <= a.size() ; i++) {
		for (int j = 1 ; j <= b.size() ; j++) {
			if (a[i - 1] == b[j - 1])
				table[i][j] = table[i - 1][j - 1] + 1;
			else
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
		}
	}
	cout << table[a.size()][b.size()] << '\n';
}
