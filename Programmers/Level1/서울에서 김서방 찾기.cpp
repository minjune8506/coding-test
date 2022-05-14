#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    auto it = find(seoul.begin(), seoul.end(), "Kim");
    answer = answer + to_string(it - seoul.begin()) + "에 있다";
    return answer;
}
