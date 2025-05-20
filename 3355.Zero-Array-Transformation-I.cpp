#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size();
        vector<int> prefix(n + 1);
        for (vector<int>& query : queries) {
            prefix[query[0]]--;
            prefix[query[1] + 1]++;
        }

        int currDifference = 0;
        for (int i = 0; i < n; ++i) {
            currDifference += prefix[i];
            int num = nums[i] + currDifference;
            if (num > 0) return false;
        }
        return true;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,0,1};
    vector<vector<int>> queries = {{0,2}};
    cout << solution.isZeroArray(nums, queries) << endl; // true
}
 