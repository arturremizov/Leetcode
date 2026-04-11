#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int, vector<int>> numToIndices;
        for (int i = 0; i < n; ++i) {
            numToIndices[nums[i]].push_back(i);
        }

        int result = INT_MAX;
        for (auto [_, indices] : numToIndices) {
            if (indices.size() < 3) continue;
            for (int i = 0; i < indices.size() - 2; ++i) {
                result = min(result,  2 * (indices[i + 2] - indices[i]));
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,1,2,3,2,1,2};
    cout << solution.minimumDistance(nums) << endl; // 8
}