#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        const int n = nums.size();

        vector<int> lis(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    lis[i] = max(lis[i], 1 + lis[j]);
                }
            }
        }
        
        vector<int> lds(n, 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[j] < nums[i]) {
                    lds[i] = max(lds[i], 1 + lds[j]);
                }
            }
        }

        int result = n;
        for (int i = 1; i < n - 1; i++) {
            if (lis[i] > 1 && lds[i] > 1) {
                result = min(result, n - lis[i] - lds[i] + 1);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {2,1,1,5,6,2,3,1};
    cout << solution.minimumMountainRemovals(nums) << endl; // 3
}