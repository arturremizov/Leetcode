#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int multiple = k;
        while (numsSet.count(multiple)) {
            multiple += k;
        }
        return multiple;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {8,2,3,4,6};
    cout << solution.missingMultiple(nums, 2) << endl; // 10
}