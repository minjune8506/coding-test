#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 0 ; i < nums.size() - 1 ; i++)
		{
			if (nums[i] == nums[i + 1])
				return true;
		}
		return false;
    }
};

int main(void)
{
	Solution s;
	vector<int> nums;

	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);

	cout << s.containsDuplicate(nums) << "\n";
}
