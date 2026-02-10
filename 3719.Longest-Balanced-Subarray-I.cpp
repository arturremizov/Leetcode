#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        const int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<int> odd, even;
            for (int j = i; j < n; ++j) {
                if (nums[j] % 2 == 1) {
                    odd.insert(nums[j]);
                } else {
                    even.insert(nums[j]);
                }

                if (odd.size() == even.size()) {
                    result = max(result, j - i + 1);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {3,2,2,5,4};
    cout << solution.longestBalanced(nums) << endl; // 5
}