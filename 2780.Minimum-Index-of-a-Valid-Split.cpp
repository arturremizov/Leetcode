#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        const int n = nums.size();
        int majorityNum = getMajority(nums);

        int totalCount = 0;
        for (int num : nums) {
            if (num == majorityNum) {
                ++totalCount;
            }
        }

        int currentCount = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == majorityNum) {
                ++currentCount;
                if (currentCount > (i + 1) / 2 && totalCount - currentCount > (n - i - 1) / 2) {
                    return i;
                }
            }
        }
        return -1;
    }
private:
    int getMajority(vector<int>& nums) {
        int majorityNum = 0;
        int count = 0;
        for (int num : nums) {
            if (count == 0) {
                majorityNum = num;
                ++count;
            } else if (num == majorityNum) {
                ++count;
            } else {
                --count;
            }
        }
        return majorityNum;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,2,2};
    cout << solution.minimumIndex(nums) << endl; // 2
}