#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        const int n = nums.size() - 2;
        int x = 0;
        for (int num : nums) {
            x ^= num;
        }
        for (int i = 0; i < n; ++i) {
            x ^= i;
        }

        int diffBit = x & -x; // rightmost differing bit

        int xor1 = 0, xor2 = 0;
        for (int num : nums) {
            if (diffBit & num) {
                xor1 ^= num;
            } else {
                xor2 ^= num;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (diffBit & i) {
                xor1 ^= i;
            } else {
                xor2 ^= i;
            }
        }
        return {xor1, xor2};
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {0,3,2,1,3,2};
    vector<int> result = solution.getSneakyNumbers(nums); // [3,2]
    cout << "[" << result[0] << "," << result[1] << "]\n";
}