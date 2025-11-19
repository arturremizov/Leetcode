#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        while (numsSet.count(original)) {
            original *= 2;
        }
        return original;        
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5,3,6,1,12};
    cout << solution.findFinalValue(nums, 3) << endl; // 24
}
