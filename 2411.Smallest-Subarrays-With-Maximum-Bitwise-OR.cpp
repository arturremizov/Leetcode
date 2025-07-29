#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        const int n = nums.size();
        vector<int> bitPos(31, -1);
        vector<int> result(n);
        for (int i = n - 1; i >= 0; --i) {
            int j = i;
            for (int bit = 0; bit < 31; ++bit) {
                if (nums[i] & (1 << bit)) {
                    bitPos[bit] = i;
                } else {
                    j = max(j, bitPos[bit]);
                }
            }
            result[i] = j - i + 1;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,0,2,1,3};
    vector<int> result = solution.smallestSubarrays(nums); // [3,3,2,2,1]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}