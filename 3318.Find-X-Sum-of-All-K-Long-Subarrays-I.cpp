#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        const int n = nums.size();
        unordered_map<int, int> numCount;
        for (int i = 0; i < k - 1; ++i) {
            numCount[nums[i]]++;
        }
        const int resultSize = n - k + 1;
        vector<int> result(resultSize);
        for (int i = 0; i < resultSize; ++i) {
            numCount[nums[i + k - 1]]++;
            priority_queue<pair<int, int>> maxHeap;
            for (auto [num, count] : numCount) {
                maxHeap.push({count, num});
            }
            int sum = 0;
            for (int j = 0; j < x; ++j) {
                if (maxHeap.empty()) break;
                auto [count, num] = maxHeap.top();
                maxHeap.pop();
                sum += num * count;
            }            
            result[i] = sum;
            numCount[nums[i]]--;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,1,2,2,3,4,2,3};
    vector<int> result = solution.findXSum(nums,6,2); // [6,10,12]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}