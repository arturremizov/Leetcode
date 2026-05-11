#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        const int n = nums.size();
        vector<int> result;
        for (int i = n - 1; i >= 0; --i) {
            int num = nums[i];
            while (num > 0) {
                int digit = num % 10;
                result.push_back(digit);
                num /= 10;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {13,25,83,77};
    vector<int> result = solution.separateDigits(nums); // [1,3,2,5,8,3,7,7]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}