#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int result = 0;
        int maxNum = INT_MIN;
        unordered_set<int> uniqueNums;
        for (int num : nums) {
            maxNum = max(maxNum, num);
            if (num <= 0) continue;
            if (uniqueNums.count(num)) continue;
            uniqueNums.insert(num);
            result += num;
        }
        if (uniqueNums.empty()) return maxNum;
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,-1,-2,1,0,-1};
    cout << solution.maxSum(nums) << endl; // 3
}