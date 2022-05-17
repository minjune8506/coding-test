#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int m = 0 ; m < commands.size() ; m++) {
        vector<int> ary;
        int i, j, k;
        
        i = commands[m][0];
        j = commands[m][1];
        k = commands[m][2];
        ary.assign(array.begin(), array.end());
        sort(ary.begin() + i - 1, ary.begin() + j);
        answer.push_back(*(ary.begin() + i - 1 + k - 1));
    }
    return answer;
}
