#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            nums[i] += (nums[nums[i]] % 1000) * 1000;
        } 
        for (int i = 0; i < n; ++i) {
            nums[i] /= 1000;
        } 
        return nums;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {0,2,1,5,3,4};
    vector<int> result = solution.buildArray(nums); // [0,1,2,4,5,3]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}