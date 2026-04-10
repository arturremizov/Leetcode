#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        const int n = nums.size();
        int result = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[i] == nums[j] && nums[j] == nums[k]) {
                        result = min(result, (j - i) + (k - j) + (k - i));                        
                    }
                }
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,1,1,3};
    cout << solution.minimumDistance(nums) << endl; // 6
}