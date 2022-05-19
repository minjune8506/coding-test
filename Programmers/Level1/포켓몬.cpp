#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int count = nums.size() / 2;
    
    sort(nums.begin(), nums.end());
    for (int i = 0 ; i < nums.size() ; i++) {
        answer++;
        count--;
        if (count <= 0)
            break ;
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
    }
    
    return answer;
}
