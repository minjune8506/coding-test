#include <string>
#include <vector>
#include <cctype>

using namespace std;

// string solution(string s) {
//     string answer = "";
//     int index = 0;
//     for (int i = 0 ; i < s.size() ; i++) {
//         if (s[i] == ' ')
//             index = -1;
//         if (isalpha(s[i])) {
//             if (index % 2 == 0) {
//                 answer += toupper(s[i]);
//             } else {
//                 answer += tolower(s[i]);
//             }
//         } else {
//             answer += s[i];
//         }
//         index++;
//     }
//     return answer;
// }

string solution(string s) {
    string answer = "";
    int index = 0;
    
    for (int i = 0 ; i < s.size() ; i++) {
        if (s[i] == ' ') {
            index = -1;
            answer += " ";
        } else if (isalpha(s[i])) {
            index & 1 ? answer += tolower(s[i]) : answer += toupper(s[i]);
        }
        index++;
    }
    return answer;
}
