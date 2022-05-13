#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0 ; i < s.size() ; i++) {
        if (s[i] == ' ') {
            answer += s[i];
        } else {
            if (islower(s[i]) && !islower(s[i] + n)) {
                answer += ('a' + (s[i] + n - 'z' - 1));
            } else if (isupper(s[i]) && !isupper(s[i] + n)) {
                answer += ('A' + (s[i] + n - 'Z' - 1));
            } else {
                answer += (s[i] + n);
            }
        }
    }
    return answer;
}

// 다른 사람 풀이 참고 코드
// string solution(string s, int n) {
//     string answer = "";

//     for (int i = 0 ; i < s.size() ; i++) {
//         if (s[i] == ' ') {
//             answer += s[i];
//         } else {
//             char start;
            
//             s[i] >= 'a' ? start = 'a' : start = 'A';
//             answer += start + ((s[i] - start + n) % 26); // 핵심 코드
//         }
//     }
//     return answer;
// }
