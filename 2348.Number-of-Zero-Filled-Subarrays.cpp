#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        long long sequence = 0;
        for (int num : nums) {
            if (num == 0) {
                ++sequence;
            } else {
                sequence = 0;
            }
            result += sequence;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,3,0,0,2,0,0,4};
    cout << solution.zeroFilledSubarray(nums) << endl; // 6
}