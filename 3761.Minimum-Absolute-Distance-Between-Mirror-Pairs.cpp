#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int, int> numToPrevIndex;
        int result = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            if (numToPrevIndex.count(num)) {
                result = min(result, i - numToPrevIndex[num]);
            }
            int reversedNum = reverseNum(num);
            numToPrevIndex[reversedNum] = i;
        }
        return result == INT_MAX ? -1 : result;
    }
private:
    int reverseNum(int num) {
        int reversedNum = 0;
        while (num > 0) {
            reversedNum *= 10;
            reversedNum += num % 10;
            num /= 10;
        }
        return reversedNum;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {12,21,45,33,54};
    cout << solution.minMirrorPairDistance(nums) << endl; // 1
}