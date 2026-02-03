#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        const int n = nums.size();
        int p = 0;
        while (p < n - 1 && nums[p] < nums[p + 1]) {
            ++p;
        }
        int q = p;
        while (q < n - 1 && nums[q] > nums[q + 1]) {
            ++q;
        }
        for (int i = q; i < n - 1; ++i) {
            if (nums[i] >= nums[i + 1]) return false;
        }
        return p > 0 && p < q && q < n - 1;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,3,5,4,2,6};
    cout << solution.isTrionic(nums) << endl; // true
}