#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size();
        sort(queries.begin(), queries.end());
        priority_queue<int> maxHeap;
        int j = 0;
        int operations = 0;
        vector<int> deltaArray(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            operations += deltaArray[i];
            while (j < queries.size() && queries[j][0] == i) {
                maxHeap.push(queries[j][1]);
                ++j;
            }
            while (operations < nums[i] && !maxHeap.empty() && maxHeap.top() >= i) {
                ++operations;
                deltaArray[maxHeap.top() + 1]--;
                maxHeap.pop();
            }

            if (operations < nums[i]) return -1;
        }
        return maxHeap.size();
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,1,1,1};
    vector<vector<int>> queries = {{1,3},{0,2},{1,3},{1,2}};
    cout << solution.maxRemoval(nums,queries) << endl; // 2
}
