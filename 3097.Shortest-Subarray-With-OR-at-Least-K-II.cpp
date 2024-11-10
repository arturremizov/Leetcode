#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int result = INT32_MAX;
        vector<int> bits(32);
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            updateBits(bits, nums[right], 1);
            int currentOR = bitsToInteger(bits);

            while (left <= right && currentOR >= k) {
                result = min(result, right - left + 1);
                updateBits(bits, nums[left], -1);
                currentOR = bitsToInteger(bits);
                ++left;
            }
        }
        return result == INT32_MAX ? -1 : result;
    }
private: 
    void updateBits(vector<int>& bits, int num, int difference) {
        for (int i = 0; i < 32; i++) {
            if (num & (1 << i)) {
                bits[i] += difference;
            }
        }
    }
    int bitsToInteger(const vector<int>& bits) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i] > 0) {
                result += (1 << i);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,3};
    cout << solution.minimumSubarrayLength(nums, 2) << endl; // 1
}