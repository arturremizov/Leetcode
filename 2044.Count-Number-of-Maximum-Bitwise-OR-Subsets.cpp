#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for (int num : nums) {
            maxOR = maxOR | num;
        }
        int result = 0;
        dfs(nums, 0, maxOR, 0, result);
        return result;
    }
private:
    void dfs(vector<int>& nums, int i, const int maxOR, int curentOR, int& result) {
        if (i == nums.size()) {
            if (curentOR == maxOR) {
                ++result;
            }
            return;
        }
        //skip i 
        dfs(nums, i + 1, maxOR, curentOR, result);
        //include i
        dfs(nums, i + 1, maxOR, curentOR | nums[i], result);
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {3,2,1,5};
    cout << solution.countMaxOrSubsets(nums) << endl; // 6
}