#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        const int n = nums.size();
        unordered_set<int> set;
        for (int i = n - 1; i >= 0; --i) {
            if (!set.count(nums[i])) {
                set.insert(nums[i]);
            } else {
                return ceil((i + 1) / 3.0);
            }
        }
        return 0;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {4,5,6,4,4};
    cout << solution.minimumOperations(nums) << endl; // 2
}