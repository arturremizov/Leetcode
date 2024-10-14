#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        long long result = 0;
        for (int i = 0; i < k; ++i) {
            int num = maxHeap.top();
            maxHeap.pop();
            result += num;
            maxHeap.push(ceil(num / 3.0));
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,10,3,3,3};
    cout << solution.maxKelements(nums, 3) << endl; // 17
}