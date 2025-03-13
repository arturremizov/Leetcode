#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        if (all_of(nums.begin(), nums.end(), [](int sum){ return sum == 0; })) return 0;

        int left = 0, right = queries.size();
        int result = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canMakeAllZero(nums, queries, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
private:
    bool canMakeAllZero(vector<int> nums, const vector<vector<int>>& queries, int k) {
        const int n = nums.size();
        vector<int> diff(n + 1, 0); 
        for (int i = 0; i < k; ++i) {
            vector<int> query = queries[i];
            int left = query[0], right = query[1], value = query[2];
            diff[left] -= value;
            diff[right + 1] += value;
        }

        int current = 0;
        for (int i = 0; i < n; ++i) {
            current += diff[i];
            nums[i] += current;
            if (nums[i] > 0) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<int> nums= {2,0,2};
    vector<vector<int>> queries = {{0,2,1},{0,2,1},{1,1,3}};
    cout << solution.minZeroArray(nums,queries) << endl; // 2
}