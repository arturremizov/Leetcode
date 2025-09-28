#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end(), greater());
        for (int i = 0; i < n - 2; ++i) {
            int a = nums[i], b = nums[i+1], c = nums[i+2];
            if ((a + b > c) && (b + c > a) && (a + c > b)) {
                return a + b + c;
            }
        }
        return 0;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {2,1,2};
    cout << solution.largestPerimeter(nums) << endl; // 5
}