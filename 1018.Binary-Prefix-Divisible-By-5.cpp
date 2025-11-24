#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        const int n = nums.size();
        vector<bool> result(n);
        int curNum = 0;
        for (int i = 0; i < n; ++i) {
            curNum = (curNum << 1 | nums[i]) % 5;
            result[i] = curNum % 5 == 0;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {0,1,1};
    vector<bool> result = solution.prefixesDivBy5(nums); // [true,false,false]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}
