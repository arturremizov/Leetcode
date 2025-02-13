#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> minHeap(nums.begin(), nums.end());
        int operations = 0;
        while (minHeap.top() < k) {
            ++operations;

            long x = minHeap.top();
            minHeap.pop();
            long y = minHeap.top();
            minHeap.pop();

            long newValue = min(x, y) * 2 + max(x, y);
            minHeap.push(newValue);
        }
        return operations;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {2,11,10,1,3};
    cout << solution.minOperations(nums, 10) << endl; // 2
}