#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) continue;
            int index = (i + nums[i]) % n;
            if (index < 0) index += n;
            result[i] = nums[index];
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {3,-2,1,1};
    vector<int> result = solution.constructTransformedArray(nums); // [1,1,1,3]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}