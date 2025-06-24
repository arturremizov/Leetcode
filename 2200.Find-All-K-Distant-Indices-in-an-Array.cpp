#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        const int n = nums.size();
        vector<int> result;
        int right = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                int left = max(right, i - k);
                right = min(n - 1, i + k) + 1;
                for (int j = left; j < right; ++j) {
                    result.push_back(j);
                }
            }        
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {3,4,9,1,3,9,5};
    vector<int> result = solution.findKDistantIndices(nums,9,1); // [1,2,3,4,5,6]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}