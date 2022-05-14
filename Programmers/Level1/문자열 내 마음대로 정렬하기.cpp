#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int index = 0;

bool cmp(string a, string b) {
    return a[index] == b[index] ? a < b : a[index] < b[index]; // 삼항 연산자로 코드 간단하게 바꿈
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    index = n;
    answer.assign(strings.begin(), strings.end());
    sort(answer.begin(), answer.end(), cmp);
    return answer;
}
