#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int result = INT_MAX;
        for (int num : nums) {
            result = min(result, sumOfDigits(num));
        }
        return result;
    }
private:
    int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};

int main() {
    Solution solution;  
    vector<int> nums = {10,12,13,14};
    cout << solution.minElement(nums) << endl; // 1
}