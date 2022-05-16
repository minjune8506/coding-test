#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int numScore = 0;
    vector<int> scores;

    for (int i = 0 ; i < dartResult.length() ; i++) {
        int score = 0;
        while (dartResult[i] >= '0' && dartResult[i] <= '9') {
            score = score * 10 + dartResult[i] - '0';
            i++;
        }
        if (dartResult[i] == 'S') {
            score = score;
        } else if (dartResult[i] == 'D') {
            score *= score;
        } else {
            score *= (score * score);
        }
        scores.push_back(score);
        if (i + 1 < dartResult.length() && (dartResult[i + 1] == '*' || dartResult[i + 1] == '#')) {
            i++;
            if (dartResult[i] == '*') {
                scores[numScore] *= 2;
                if (numScore > 0) {
                    scores[numScore - 1] *= 2;
                }
            } else {
                scores[numScore] *= -1;
            }
        }
        numScore++;
    }
    for (int i = 0 ; i < scores.size() ; i++) {
        answer += scores[i];
    }
    return answer;
}
