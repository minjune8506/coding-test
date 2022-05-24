#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(string s) {
    vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six",
                             "seven", "eight", "nine"};
    int answer = 0;
    string num_str;
    string temp = "";
    
    for (int i = 0 ; i < s.length() ; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num_str += s[i];
        } else {
            temp += s[i];
            for (int j = 0 ; j < numbers.size() ; j++) {
                if (numbers[j] == temp) {
                    num_str += to_string(j);
                    temp = "";
                }
            }
        }
    }
    for (int i = 0 ; i < num_str.size() ; i++) {
        answer = answer * 10 + (num_str[i] - '0');
    }
    return answer;
}
