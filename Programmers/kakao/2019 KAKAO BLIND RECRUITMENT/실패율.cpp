#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, double> &a, const pair<int, double> &b) {
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double> > rate;
    
    for (int i = 1 ; i <= N ; i++) {
        int reached = 0;
        int notClear = 0;
        for (int j = 0 ; j < stages.size() ; j++) {
            if (stages[j] >= i) { // 스테이지에 도달한 사람 수
                reached++;
                if (stages[j] == i) { // 스테이지에 머물러 있는 사람 수
                    notClear++;
                }
            }
        }
        reached == 0 ? rate.push_back(make_pair(i, 0)) : rate.push_back(make_pair(i, notClear / (double) reached));
    }
    stable_sort(rate.begin(), rate.end(), cmp); // 안정 정렬
    for (int i = 0 ; i < rate.size() ; i++) {
        answer.push_back(rate[i].first);
    }
    return answer;
}
