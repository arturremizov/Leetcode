#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int curZeroWindow = k;
        for (int num : nums) {
            if (num == 0) {
                ++curZeroWindow;
            } else {
                if (curZeroWindow < k) return false;
                curZeroWindow = 0;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,0,0,0,1,0,0,1};
    cout << solution.kLengthApart(nums, 2) << endl; // true
}
