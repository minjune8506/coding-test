#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for (int i = 0 ; i < new_id.length() ; i++) {
        if (isalpha(new_id[i])) {
            new_id[i] = tolower(new_id[i]); // 소문자로 변환
        }
        if (new_id[i] != '_' && new_id[i] != '-' && !isalpha(new_id[i]) &&
            new_id[i] != '.' && !(new_id[i] >= '0' && new_id[i] <= '9')) {
            new_id.erase(i, 1); // 허용되지 않은 문자 제거
            i--;
        }
    }
    for (int i = 0 ; i < new_id.length() ; i++) {
        int cnt = 0;
        int start = 0;
        while (new_id[i] == '.') {
            if (cnt == 0)
                start = i;
            cnt++;
            i++;
        }
        if (cnt > 1) {
            new_id.erase(start, cnt - 1);
            i -= cnt;
        }
    }
    if (new_id.length() && (new_id[0] == '.' || new_id[new_id.length() - 1] == '.')) {
		// 시작문자나 끝 문자가 '.'인 경우 제거
        if (new_id[0] == '.') {
			new_id.erase(0, 1);
		}
        else {
			new_id.erase(new_id.length() - 1, 1);
		}
    }
    if (!new_id.length()) {
		// 빈문자열인 경우 a 문자 추가
		new_id.append("a");
    }
    if (new_id.length() >= 16) { // 문자열의 길이가 16을 넘을 경우
        new_id.erase(15); // 15번째 인덱스 부터 (15개의 문제를 놔두고 그 이후부터) 제거
	}
    if (new_id.length() && (new_id[0] == '.' || new_id[new_id.length() - 1] == '.')) {
		// 시작 문자나 끝 문자가 '.'인 경우 제거
        if (new_id[0] == '.') {
			new_id.erase(0, 1);
		}
        else {
			new_id.erase(new_id.length() - 1, 1);
		}
    }
    if (new_id.length() <= 2) { // 문자열의 길이가 2보다 작을 경우
        while (new_id.length() != 3) { // 길이가 3이 될때까지 마지막 문자 추가
            new_id += new_id[new_id.length() - 1];
        }
    }
    answer = new_id;
    return answer;
}
