#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<pair<int, int> > ary;
    
    for (int i = progresses.size() - 1 ; i >= 0 ; i--) {
        ary.push_back(make_pair(i, progresses[i])); // 2,55 1,30 0,93
    }
    while (ary.size()) {
        int cnt = 0;
        for (int i = ary.size() - 1 ; i >= 0 ; i--) {
            ary[i].second += speeds[ary[i].first];
        }
        while (ary.size() && ary[ary.size() - 1].second >= 100) {
            cnt++;
            ary.pop_back();
        }
        if (cnt) {
            answer.push_back(cnt);
        }
    }
    return answer;
}
