#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int curMin = nums[0], curMax = nums[0];
        int prevMax = 0;
        for (int num : nums) {
            if (countBits(num) == countBits(curMin)) {
                curMin = min(curMin, num);
                curMax = max(curMax, num);
            } else {
                if (curMin < prevMax) {
                    return false;
                }

                prevMax = curMax;
                curMin = num;
                curMax = num;
            }
        }
        
        if (curMin < prevMax) {
            return false;
        }

        return true;    
    }
private: 
    int countBits(int num) {
        int result = 0;
        while (num) {
            result += num & 1;
            num = num >> 1;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {8,4,2,30,15};
    cout << solution.canSortArray(nums) << endl; // true
}