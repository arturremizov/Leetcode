#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderCount; //reminder : count
        remainderCount[0] = 1;
        int currentSum = 0;
        int result = 0;
        for (int num : nums) {
            currentSum += num;
            int remainder = currentSum % k;
            if (remainder < 0) {
                remainder += k;
            }
            result += remainderCount[remainder];
            remainderCount[remainder] ++;
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums1 = {4,5,0,-2,-3,1};
    cout << solution.subarraysDivByK(nums1, 5) << endl; // 7
    vector<int> nums2 = {-1,2,9};
    cout << solution.subarraysDivByK(nums2, 2) << endl; // 2
}