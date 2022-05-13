#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if (s.length() != 4 && s.length() != 6) {
        answer = false;
        return answer;
    }
    for (int i = 0 ; i < s.size() ; i++) {
        if (!isdigit(s[i])) {
            answer = false;
            return answer;
        }
    }
    return answer;
}
