#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,set<string> > table;
    set<string> type;
    
    for (int i = 0 ; i < clothes.size() ; i++) {
        table[clothes[i][1]].insert(clothes[i][0]);
        type.insert(clothes[i][1]);
    }
    for (auto it = type.begin() ; it != type.end() ; it++) {
        answer *= (table[*it].size() + 1);
    }
    answer -= 1;
    return answer;
}
