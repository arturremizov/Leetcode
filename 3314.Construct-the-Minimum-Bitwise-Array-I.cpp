#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> result(n, -1);
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            for (int value = 1; value < num; ++value) {
                if ((value | (value + 1)) == num) {
                    result[i] = value;
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {2,3,5,7};
    vector<int> result = solution.minBitwiseArray(nums); // [-1,1,4,3]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}