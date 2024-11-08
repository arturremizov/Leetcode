#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        const int n = nums.size();
        int xorValue = 0;
        for (int num : nums) {
            xorValue ^= num;
        }
        int mask = pow(2, maximumBit) - 1;
        vector<int> answer;
        for (int i = n - 1; i >= 0; --i) {
            answer.push_back(xorValue ^ mask);
            xorValue ^= nums[i];
        }
        return answer;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {0,1,1,3};
    vector<int> result = solution.getMaximumXor(nums, 2); // [0,3,2,3]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}