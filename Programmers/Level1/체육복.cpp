#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// int solution(int n, vector<int> lost, vector<int> reserve) {
//     int answer = n - lost.size();

//     sort(lost.begin(), lost.end());
//     sort(reserve.begin(), reserve.end());

//     for (int i = 0 ; i < lost.size(); i++) {
//         for (int j = 0 ; j < reserve.size() ; j++) {
//             if (lost[i] == reserve[j]) {
//                 lost[i] = -42;
//                 reserve[j] = -42;
//                 answer++;
//                 break ;
//             }
//         }
//     }

//     for (int i = 0 ; i < lost.size() ; i++) {
//         for (int j = 0 ; j < reserve.size() ; j++) {
//             if (lost[i] + 1 == reserve[j] || lost[i] - 1 == reserve[j]) {
//                 lost[i] = -42;
//                 reserve[j] = -42;
//                 answer++;
//                 break ;
//             }
//         }
//     }
//     return answer;
// }

int student[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for (int i : lost) {
        student[i]--;
    }
    for (int i : reserve) {
        student[i]++;
    }
    for (int i = 1 ; i < n + 1 ; i++) {
        if (student[i] == -1) {
            if (student[i - 1] == 1) {
                student[i] = 0;
                student[i - 1] = 0;
            } else if (student[i + 1] == 1){
                student[i] = 0;
                student[i + 1] = 0;
            }
        }
    }
    for (int i = 1 ; i < n + 1 ; i++) {
        if (student[i] >= 0) {
            answer++;
        }
    }
    return answer;
}
