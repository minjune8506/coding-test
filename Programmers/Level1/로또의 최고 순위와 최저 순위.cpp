#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt = 0;
    int zeroCnt = 0;

    for (int i = 0 ; i < lottos.size() ; i++) {
		if (lottos[i] == 0) {
			zeroCnt++;
		}
        if (find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end()) {
            cnt++;
        }
    }
    if (zeroCnt + cnt < 2) {
        answer.push_back(6);
    } else {
        answer.push_back(win_nums.size() - (zeroCnt + cnt) + 1);
    }
    if (cnt < 2) {
        answer.push_back(6);
    } else {
        answer.push_back(win_nums.size() - cnt + 1);    
    }
    return answer;
}
	