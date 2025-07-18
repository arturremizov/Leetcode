#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        const int n = nums.size() / 3;
        vector<long long> part1(n + 1);
        long long sum = 0;
        priority_queue<int> maxHeap;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            maxHeap.push(nums[i]);
        }
        part1[0] = sum;
        for (int i = n; i < n * 2; ++i) {
            sum += nums[i];
            maxHeap.push(nums[i]);
            sum -= maxHeap.top();
            maxHeap.pop();
            part1[i - (n - 1)] = sum;
        }

        long long part2 = 0;
        priority_queue<int, vector<int>, greater<>> minHeap;
        for (int i = n * 3 - 1; i >= n * 2; --i) {
            part2 += nums[i];
            minHeap.push(nums[i]);
        }

        long long result = part1[n] - part2;
        for (int i = n * 2 - 1; i >= n; --i) {
            part2 += nums[i];
            minHeap.push(nums[i]);
            part2 -= minHeap.top();
            minHeap.pop();
            result = min(result, part1[i - n] - part2);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {7,9,5,8,1,3};
    cout << solution.minimumDifference(nums) << endl; // 1
}