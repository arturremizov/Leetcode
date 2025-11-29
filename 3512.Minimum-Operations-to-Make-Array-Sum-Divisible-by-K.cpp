#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return sum % k;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {3,9,7};
    cout << solution.minOperations(nums,5) << endl; // 4
}