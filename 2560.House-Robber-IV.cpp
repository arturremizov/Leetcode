#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int result = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (isValid(mid, nums, k)) {
                right = mid - 1;
                result = mid;
            } else {
                left = mid + 1;
            }       
        }
        return result;
    }
private:
    bool isValid(int capability, vector<int>& nums, int k) {
        int i = 0;
        int count = 0;
        while (i < nums.size()) {
            if (nums[i] <= capability) {
                count++;
                i += 2;
            } else {
                i++;
            }

            if (count == k) break;
        }
        return count == k;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2,3,5,9};
    cout << solution.minCapability(nums, 2) << endl; // 5
}