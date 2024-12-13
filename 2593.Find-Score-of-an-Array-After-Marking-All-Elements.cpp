#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        const int n = nums.size();
        vector<bool> marked(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (int i = 0; i < n; ++i) {
            minHeap.push({nums[i], i});
        }
        long long result = 0;
        while (!minHeap.empty()) {
            auto [num, i] = minHeap.top();
            minHeap.pop();
            if (marked[i]) continue;
            result += num;
            marked[i] = true;
            if (i - 1 >= 0) {
                marked[i - 1] = true; 
            }
            if (i + 1 < n) {
                marked[i + 1] = true; 
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> gifts = {2,1,3,4,5,2};
    cout << solution.findScore(gifts) << endl; // 7
}