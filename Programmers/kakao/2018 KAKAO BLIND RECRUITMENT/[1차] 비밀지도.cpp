#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string int_to_bit(int n, int num) {
    string str;
    
    while (num > 0) {
        str += ('0' + (num % 2));
        num /= 2;
    }
    while (str.size() < n) {
        str += '0';
    }
    reverse(str.begin(), str.end());
    return str;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string a;
    for (int i = 0 ; i < arr1.size() ; i++) {
        string bits1 = int_to_bit(n, arr1[i]);
        string bits2 = int_to_bit(n, arr2[i]);
        string line;
        for (int j = 0 ; j < n ; j++) {
            if (bits1[j] == '1' || bits2[j] == '1') {
                line += '#';
            } else {
                line += ' ';
            }
        }
        answer.push_back(line);
    }
    return answer;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
	vector<string> answer;

	for (int i = 0; i < n; i++) {
		arr1[i] = arr1[i] | arr2[i];
		string ans = "";
		for (int j = 0; j < n; j++) {
			if (arr1[i] % 2 == 0)
				ans = " " + ans;
			else
				ans = "#" + ans;
			arr1[i] = arr1[i] >> 1;
		}
		answer.push_back(ans);
	}
	return answer;
}
