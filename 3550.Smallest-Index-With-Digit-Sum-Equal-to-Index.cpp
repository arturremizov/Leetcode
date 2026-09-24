#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (digitsSum(nums[i]) == i) {
                return i;
            }
        }
        return -1;
    }
private:
    int digitsSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,3,2};
    cout << solution.smallestIndex(nums) << endl; // 2
}