#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int, vector<int>> numToIndices;
        for (int i = 0; i < n; ++i) {
            numToIndices[nums[i]].push_back(i);
        }
        vector<long long> result(n);
        for (auto& [_, indices] : numToIndices) {
            const int count = indices.size();
            long long leftSum = 0;
            long long rightSum = accumulate(indices.begin(), indices.end(), 0LL);
            for (int i = 0; i < count; ++i) {
                rightSum -= indices[i];
                long long left = abs(1LL * indices[i] * i - leftSum);
                long long right = abs(1LL * indices[i] * (count - i - 1) - rightSum);
                result[indices[i]] = left + right;
                leftSum += indices[i];
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,3,1,1,2};
    vector<long long> result = solution.distance(nums); // [5,0,3,4,0]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}