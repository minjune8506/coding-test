#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, int> cnt; // 신고 당한 횟수 관리 테이블
    unordered_map<string, set<string> > table; // 신고한 사람을 관리하는 테이블
    
    for (int i = 0 ; i < report.size() ; i++) {
        int del = report[i].find(' '); // 공백을 기준으로 문자열 parsing
        string from = report[i].substr(0, del);
        string to = report[i].substr(del + 1, report[i].size());
        auto result = table[from].insert(to); // 유저별로 신고한 사람 집합에 추가 (from -> to)
        if (result.second) // insert 성공 (중복되지 않음)
            cnt[to]++; // 신고당한 횟수 증가
    }
    for (int i = 0 ; i < id_list.size() ; i++) {
        int ans = 0;
        for (auto it = table[id_list[i]].begin() ; it != table[id_list[i]].end() ; it++) {
            if (cnt[*it] >= k) {
                ans++;
            }
        }
        answer.push_back(ans);
    }
    return answer;
}
