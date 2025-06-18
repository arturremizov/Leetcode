#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i += 3) {
            if (nums[i + 2] - nums[i] > k) return {};
            vector<int> array(nums.begin() + i, nums.begin() + i + 3);
            result.push_back(array);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    vector<vector<int>> result = solution.divideArray(nums, 2); // [[1,1,3],[3,4,5],[7,8,9]]
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]\n";
    }
}