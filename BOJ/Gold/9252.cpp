/**
 * 9252 : LCS2
 * 
 * LCS (Longest Common Subsequence, 최장 공통 부분 수열) 구하기
 * 
 * 입력 : 알파벳 대문자로만 이루어져 있으며, 최대 1000글자
 * 출력 : 입력으로 주어진 두 문자열의 LCS 길이 출력 + LCS 문자열 출력
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int table[1001][1001] = {0, };
string a, b;
string answer;

void getLCS(int i, int j) {
	if (i <= 0 || j <= 0) { 
		return ;
	}
	if (a[i - 1] == b[j - 1]) {
		getLCS(i - 1, j - 1);
		answer += a[i - 1];
	} else {
		if (max(table[i - 1][j], table[i][j - 1]) == table[i - 1][j]) {
			getLCS(i - 1 , j);
		} else {
			getLCS(i, j - 1);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;
	int a_size = a.length();
	int b_size = b.length();
	for (int i = 1 ; i <= a_size ; i++) {
		for (int j = 1 ; j <= b_size ; j++) {
			if (a[i - 1] == b[j - 1])
				table[i][j] = table[i - 1][j - 1] + 1;
			else
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
		}
	}
	cout << table[a.size()][b.size()] << '\n';
	if (table[a.size()][b.size()] != 0) {
		getLCS(a_size, b_size);
		cout << answer << '\n';
	}
}
