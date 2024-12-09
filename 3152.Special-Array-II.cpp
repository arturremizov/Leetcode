#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size();
        vector<int> prefix(n);
        for (int i = 1; i < n; ++i) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = prefix[i - 1];
            }
        }
        vector<bool> result;
        for (auto query : queries) {
            int start = query[0], end = query[1];
            result.push_back(prefix[end] - prefix[start] == 0);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {4,3,1,6};
    vector<vector<int>> queries = {{0,2}, {2,3}};
    vector<bool> result = solution.isArraySpecial(nums, queries);
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}