#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        return gcd(maxNum, minNum);
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
    vector<int> nums = {2,5,6,9,10};
    cout << solution.findGCD(nums) << endl; // 2
}