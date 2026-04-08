#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto& query : queries) {
            int l = query[0], r = query[1], k = query[2], v = query[3];
            for (int i = l; i <= r; i += k) {
                nums[i] = (1LL * nums[i] * v) % int(1e9 + 7);
            }
        }

        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {2,3,1,5,4};
    vector<vector<int>> queries = {{1,4,2,3}, {0,2,1,2}};
    cout << solution.xorAfterQueries(nums, queries) << endl; // 31
}