#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i], i});
        }
        while (k--) {
            auto [num, i] = minHeap.top();
            minHeap.pop();
            nums[i] = num * multiplier;
            minHeap.push({num * multiplier, i});
        }
        return nums;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {2,1,3,5,6};
    vector<int> result = solution.getFinalState(nums,5,2); // [8,4,6,5,6]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}