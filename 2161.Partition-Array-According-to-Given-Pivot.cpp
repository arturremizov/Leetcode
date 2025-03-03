#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        const int n = nums.size();
        vector<int> result(n);

        int i = 0, j = n - 1;
        int i2 = 0, j2 = n - 1;
        while (i < n) {
            if (nums[i] < pivot) {
                result[i2] = nums[i];
                ++i2;
            } 
            if (nums[j] > pivot) {
                result[j2] = nums[j];
                --j2;
            }
            ++i, --j;
        }
        while (i2 <= j2) {
            result[i2++] = pivot;
            result[j2--] = pivot;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {9,12,5,10,14,3,10};
    vector<int> result = solution.pivotArray(nums, 10); //[9,5,3,10,10,12,14]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        }
    }
}