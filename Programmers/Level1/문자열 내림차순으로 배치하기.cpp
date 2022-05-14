#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer;
    
    answer.assign(s.begin(), s.end());
    sort(answer.begin(), answer.end(), greater<char>());
    return answer;
}
