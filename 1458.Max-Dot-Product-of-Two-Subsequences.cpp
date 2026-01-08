#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size(), m = nums2.size();
        vector<vector<int>> memo(n, vector<int>(m, INT_MIN));
        return dfs(0, 0, nums1, nums2, memo);
    }
private:
    int dfs(int i, int j,
            vector<int>& nums1, vector<int>& nums2,
            vector<vector<int>>& memo) {

        if (i == nums1.size() || j == nums2.size()) return INT_MIN;
        if (memo[i][j] != INT_MIN) return memo[i][j];

        int product = nums1[i] * nums2[j];

        int includeResult = product; 
        int next = dfs(i + 1, j + 1, nums1, nums2, memo); 
        if (next != INT_MIN) includeResult += next;

        int skipResult = max(
            dfs(i + 1, j, nums1, nums2, memo),
            dfs(i, j + 1, nums1, nums2, memo)
        );

        return memo[i][j] = max({
            product, // take and stop
            includeResult, // take and continue
            skipResult // skip and continue
        });
    }
};

int main() {
    Solution solution; 
    vector<int> nums1 = {2,1,-2,5};
    vector<int> nums2 = {3,0,-6};
    cout << solution.maxDotProduct(nums1,nums2) << endl; // 18
}