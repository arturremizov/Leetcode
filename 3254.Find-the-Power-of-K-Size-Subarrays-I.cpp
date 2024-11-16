#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> result;
        int count = 1;
        int left = 0;
        for (int right = 0; right < n; ++right){
            if (right > 0 && nums[right - 1] + 1 == nums[right]) {
                ++count;
            }
            if (right - left + 1 > k) {
                if (nums[left] + 1 == nums[left + 1]) {
                    --count;
                }
                ++left;
            } 
            if (right - left + 1 == k) {
                if (count == k) {
                    result.push_back(nums[right]);
                } else {
                    result.push_back(-1);
                }
            }            
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,3,4,3,2,5};
    vector<int> result = solution.resultsArray(nums, 3); // [3,4,-1,-1,-1]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}