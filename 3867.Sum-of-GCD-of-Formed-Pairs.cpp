#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        const int n = nums.size();
        vector<int> prefixGcd(n);
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long result = 0;
        for (int i = 0; i < n / 2; ++i) {
            result += gcd(prefixGcd[n - i - 1], prefixGcd[i]);
        }
        return result;
    }
private:
    int gcd(int a, int b) {
        while (b) {
            int reminder = a % b;
            a = b;
            b = reminder;
        }
        return a;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {3,6,2,8};
    cout << solution.gcdSum(nums) << endl; // 5
}