#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        const int n = nums.size();
        long long result = 0;
        multiset<int> window;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            window.insert(nums[right]);
            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[left]));
                ++left;
            }
            result += right - left + 1;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {5,4,2,4};
    cout << solution.continuousSubarrays(nums) << endl; // 8
}