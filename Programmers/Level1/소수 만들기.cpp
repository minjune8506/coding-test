#include <vector>
#include <iostream>

using namespace std;

int answer = 0;

bool isPrime(int num) {
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num ; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void getSum(vector<int> nums, int start, int cnt, int sum) {
    if (cnt == 3) {
        if (isPrime(sum))
            answer++;
        return ;
    }
    if (start >= nums.size()) {
        return ;
    }
    for (int i = start; i < nums.size() ; i++) {
        getSum(nums, i + 1, cnt + 1, sum + nums[i]);
    }
}

int solution(vector<int> nums) {
    for (int i = 0 ; i < nums.size() ; i++) {
        getSum(nums, i + 1, 1, nums[i]);
    }
    return answer;
}
