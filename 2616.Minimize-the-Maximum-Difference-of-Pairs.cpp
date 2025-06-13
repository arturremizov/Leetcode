#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 1e9;
        int result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(mid, nums, p)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
private:
    bool isValid(int threshold, vector<int>& nums, int p) {
        int i = 0;
        int pairsTotal = 0;
        while (i < nums.size() - 1) {
            if (abs(nums[i] - nums[i + 1]) <= threshold) {
                i += 2;
                if (++pairsTotal == p) return true;
            } else {
                ++i;
            }
        }
        return false;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {10,1,2,7,1,3};
    cout << solution.minimizeMax(nums, 2) << endl; // 1
}