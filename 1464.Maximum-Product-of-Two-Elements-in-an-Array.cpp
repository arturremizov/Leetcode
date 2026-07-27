#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = 0, b = 0;
        for (int num : nums) {
            int prevA = a;
            a = max(a, num);
            b = max(b, min(num, prevA));
        }
        return (a - 1) * (b - 1);
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {3,4,5,2};
    cout << solution.maxProduct(nums) << endl; // 12
}