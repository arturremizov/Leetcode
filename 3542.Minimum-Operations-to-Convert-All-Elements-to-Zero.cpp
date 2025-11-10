#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        stack<int> stack;
        for (int num : nums) {
            while (!stack.empty() && stack.top() > num) {
                stack.pop();
            }
            if (num == 0) continue;
            if (stack.empty() || stack.top() != num) {
                stack.push(num);
                ++result;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,1,2,1,2};
    cout << solution.minOperations(nums) << endl; // 4
}