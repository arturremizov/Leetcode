#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_value = 0;
        for (int num : nums) {
            xor_value ^= num;
        }
        int diffBit = 1; // 00001
        while (!(xor_value & diffBit)) {
            diffBit = diffBit << 1;
        }
        int a = 0, b = 0;
        for (int num : nums) {
            if (diffBit & num) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        return {a, b};
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums = {1,2,1,3,2,5}; // [3,5]
    vector<int> result = solution.singleNumber(nums);
    for (int num : result) {
        cout << num << endl;
    }
}