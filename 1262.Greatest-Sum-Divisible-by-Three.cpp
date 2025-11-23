#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sumTotal = 0;
        int smallestOne = 1e4 + 1;
        int smallestTwo = 1e4 + 1;
        for (int num : nums) {
            sumTotal += num;
            if (num % 3 == 1) {
                smallestTwo = min(smallestTwo, smallestOne + num);
                smallestOne = min(smallestOne, num);
            } 
            if (num % 3 == 2) {
                smallestOne = min(smallestOne, smallestTwo + num);
                smallestTwo = min(smallestTwo, num);
            }
        }

        if (sumTotal % 3 == 0) {
            return sumTotal;
        }
        if (sumTotal % 3 == 1) {
            return sumTotal - smallestOne;
        }
        if (sumTotal % 3 == 2) {
            return sumTotal - smallestTwo;
        }
        return 0; 
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {3,6,5,1,8};
    cout << solution.maxSumDivThree(nums) << endl; // 18
}
