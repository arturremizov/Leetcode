#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a = -1001, b = -1001, c = -1001;
        int minA = 1001, minB = 1001;
        for (int num : nums) {
            int prevA = a, prevB = b;
            a = max(a, num);
            b = max(b, min(num, prevA));
            c = max(c, min(prevB, num));

            int prevMinA = minA;
            minA = min(minA, num);
            minB = min(minB, max(num, prevMinA));
        }
        return max(a * b * c, minA * minB * a);
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,3,4};
    cout << solution.maximumProduct(nums) << endl; // 24
}