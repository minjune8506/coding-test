#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// int solution(vector<vector<int>> sizes) {
//     vector<int> width;
//     vector<int> height;
//     int answer = 0;
    
//     for (int i = 0 ; i < sizes.size() ; i++) {
//         if (sizes[i][0] > sizes[i][1]) {
//             width.push_back(sizes[i][0]);
//             height.push_back(sizes[i][1]);
//         } else {
//             width.push_back(sizes[i][1]);
//             height.push_back(sizes[i][0]);
//         }
//     }
//     sort(width.begin(), width.end(), greater<int>());
//     sort(height.begin(), height.end(), greater<int>());
//     answer = width[0] * height[0];
//     return answer;
// }

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int wMax = 0;
    int hMax = 0;
    
    for (int i = 0 ; i < sizes.size() ; i++) {
        wMax = max(wMax, max(sizes[i][0], sizes[i][1]));
        hMax = max(hMax, min(sizes[i][0], sizes[i][1]));
    }
    answer = wMax * hMax;
    return answer;
}
