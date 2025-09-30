#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        const int n = nums.size();
        vector<int> newNums = nums;
        for (int i = n - 1; i > 0; --i) {
            vector<int> temp(i);
            for (int j = 0; j < i; ++j) {
                temp[j] = (newNums[j] + newNums[j+1]) % 10;
            }
            newNums = temp;
        }
        return newNums[0];
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,3,4,5};
    cout << solution.triangularSum(nums) << endl; // 8
}