#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        const int k = nums.size();
        int left = nums[0][0];
        int right = nums[0][0];
        // num, index of the list, index of the nums
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        for (int i = 0; i < k; i++) {
            left = min(left, nums[i][0]);
            right = max(right, nums[i][0]);
            minHeap.push({nums[i][0], i, 0});
        }

        vector<int> result = {left, right};
        while (true) {
            auto [num, indexOfList, indexOfNums] = minHeap.top();
            minHeap.pop();
            if (++indexOfNums == nums[indexOfList].size()) break;

            int nextNum = nums[indexOfList][indexOfNums];
            minHeap.push({nextNum, indexOfList, indexOfNums});

            auto [newMinNum, _, __] = minHeap.top();
            left = newMinNum;
            right = max(right, nextNum);
            
            if (right - left < result[1] - result[0]) {
                result[0] = left;
                result[1] = right;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> nums = {{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
    vector<int> result = solution.smallestRange(nums); // [20,24]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}