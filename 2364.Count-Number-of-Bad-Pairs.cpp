#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        const int n = nums.size();
        long long goodPairs = 0;
        long long totalPairs = 0;
        unordered_map<int, int> groups;
        for (int i = 0; i < n; ++i) {
            totalPairs += i;
            goodPairs += groups[nums[i] - i];
            groups[nums[i] - i]++;
        }
        return totalPairs - goodPairs;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {4,1,3,3};
    cout << solution.countBadPairs(nums) << endl; // 5
}