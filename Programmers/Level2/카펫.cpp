#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = (brown + 4) / 2;
    
    cout << sum << endl;
    for (int h = 0 ; h < sum ; h++) {
        for (int w = h ; w < sum ; w++) {
            if (w + h == sum && (w - 2) * (h - 2) == yellow) {
                answer.push_back(w);
                answer.push_back(h);
                break ;
            }
        }
    }
    return answer;
}
