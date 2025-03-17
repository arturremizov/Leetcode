#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> numCount;
        for (int num : nums) {
            numCount[num]++;
        }
        for (auto [_, count] : numCount) {
            if (count % 2 != 0) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3,2,3,2,2,2};
    cout << solution.divideArray(nums) << endl; // true
}