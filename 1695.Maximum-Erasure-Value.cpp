#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int result = 0;
        int sum = 0;
        unordered_map<int, int> numsCount;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (left < right && numsCount.count(nums[right])) {
                int leftNum = nums[left];
                sum -= leftNum;
                numsCount[leftNum]--;
                if (numsCount[leftNum] == 0) {
                    numsCount.erase(leftNum);
                }
                left++;
            }
            sum += nums[right];
            result = max(result, sum);
            numsCount[nums[right]]++;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {5,2,1,2,5,2,1,2,5};
    cout << solution.maximumUniqueSubarray(nums) << endl; // 8
}