#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> answer1 = {1, 2, 3, 4, 5};
    vector<int> answer2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> answer3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int cnt[3] = {0, };
    
    for (int i = 0 ; i < answers.size() ; i++) {
        if (answers[i] == answer1[i % (answer1.size())])
            cnt[0]++;
        if (answers[i] == answer2[i % (answer2.size())])
            cnt[1]++;
        if (answers[i] == answer3[i % (answer3.size())])
            cnt[2]++;
    }
    int maxVal = max(max(cnt[0], cnt[1]), cnt[2]);
    for (int i = 0 ; i < 3 ; i++) {
        if (maxVal == cnt[i]) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}
