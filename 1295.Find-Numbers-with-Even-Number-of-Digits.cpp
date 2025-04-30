#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for (int num : nums)
            if (hasEvenNumberOfDigits(num)) 
                ++result;
        return result;
    }
private:
    bool hasEvenNumberOfDigits(int num) {
        int digits = 0; 
        while (num > 0) {
            num /= 10;
            ++digits;
        }
        return digits % 2 == 0;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {12,345,2,6,7896};
    cout << solution.findNumbers(nums) << endl; // 2
}
 