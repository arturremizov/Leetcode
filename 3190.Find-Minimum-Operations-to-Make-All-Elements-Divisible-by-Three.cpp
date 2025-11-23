#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            if (num % 3 != 0) {
                ++result;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,3,4};
    cout << solution.minimumOperations(nums) << endl; // 3
}