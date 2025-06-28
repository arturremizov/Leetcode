#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<pair<int, int>> indexToNum(n);
        for (int i = 0; i < n; ++i) {
            indexToNum[i] = {i, nums[i]};
        }
        sort(indexToNum.begin(), indexToNum.end(), [] (const auto& lhs, const auto& rhs) {
            return lhs.second > rhs.second;
        });
        sort(indexToNum.begin(), indexToNum.begin() + k);
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(indexToNum[i].second);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {2,1,3,3};
    vector<int> result = solution.maxSubsequence(nums,2); // [3,3]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}