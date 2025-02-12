#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> groups;
        for (int num : nums) {
            groups[sumOfDigits(num)].push(num);
        }
        int result = -1;
        for (auto& [_, maxHeap] : groups) {
            if (maxHeap.size() < 2) continue;

            int num1 = maxHeap.top();
            maxHeap.pop();
            int num2 = maxHeap.top();
            maxHeap.pop();

            result = max(result, num1 + num2);
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
    vector<int> nums = {18,43,36,13,7};
    cout << solution.maximumSum(nums) << endl; // 54
}