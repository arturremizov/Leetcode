#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
private:
    int dfs(vector<int>& nums, int i, int total) {
        if (i == nums.size()) return total;
        return dfs(nums, i + 1, total ^ nums[i]) + dfs(nums, i + 1, total);
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums = {5,1,6};
    cout << solution.subsetXORSum(nums) << endl; // 28
}