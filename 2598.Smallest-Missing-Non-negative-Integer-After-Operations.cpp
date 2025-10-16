#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> reminderToCount;
        for (int num : nums) {
            int reminder = (num % value + value) % value;
            reminderToCount[reminder]++;
        }
        int mex = 0;
        while (reminderToCount[mex % value] > 0) {
            reminderToCount[mex % value]--;
            ++mex;
        }
        return mex;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,-10,7,13,6,8};
    cout << solution.findSmallestInteger(nums, 5) << endl; // 4
}