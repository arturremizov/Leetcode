#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        const int n = nums.size();
        unordered_set<int> numsSet(nums.begin(), nums.end());
        unordered_map<int, int> countNums;
        int result = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            countNums[nums[right]]++;
            while (countNums.size() == numsSet.size()) {
                result += n - right;
                int num = nums[left++];
                countNums[num]--;
                if (countNums[num] == 0) {
                    countNums.erase(num);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,3,1,2,2};
    cout << solution.countCompleteSubarrays(nums) << endl; // 4
}
