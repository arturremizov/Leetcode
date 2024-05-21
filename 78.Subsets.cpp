#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        dfs(nums, 0, subset, result);
        return result;
    }
private:
    void dfs(vector<int>& nums, int i, vector<int> subset, vector<vector<int>>& result) {
        if (i == nums.size()) {
            result.push_back(subset);
            return;
        }
        dfs(nums, i + 1, subset, result);

        subset.push_back(nums[i]);
        dfs(nums, i + 1, subset, result);
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = solution.subsets(nums);
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "] ";
    }
}