#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorResult = 0;
        for (int num : nums) {
            xorResult ^= num;
        }
        xorResult ^= k;
        return bitset<32>(xorResult).count();
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums = {2,1,3,4};
    cout << solution.minOperations(nums, 1) << endl; // 2
}