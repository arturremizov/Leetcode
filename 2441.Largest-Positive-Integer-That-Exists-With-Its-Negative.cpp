#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int result = -1;
        bitset<2048> bitset;
        for (int num : nums) {
            int absNum = abs(num);
            if (absNum > result && bitset[-num + 1024]) {
                result = absNum;
            } 
            bitset[num + 1024] = true;
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums1 = {-1,2,-3,3};
    cout << solution.findMaxK(nums1) << endl; // 3

    vector<int> nums2 = {-1,10,6,7,-7,1};
    cout << solution.findMaxK(nums2) << endl; // 7

    vector<int> nums3 = {-10,8,6,7,-2,-3};
    cout << solution.findMaxK(nums3) << endl; // -1
}