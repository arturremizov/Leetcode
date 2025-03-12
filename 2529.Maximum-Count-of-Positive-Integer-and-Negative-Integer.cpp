#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negativeCount = 0;
        int positiveCount = 0;
        for (int num : nums) {
            if (num < 0) {
                ++negativeCount;
            } else if (num > 0) {
                ++positiveCount;
            }
        }
        return max(negativeCount, positiveCount);
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {-2,-1,-1,1,2,3};
    cout << solution.maximumCount(nums) << endl; // 3
}