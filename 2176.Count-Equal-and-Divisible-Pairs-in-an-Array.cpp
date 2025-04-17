#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> numIndices;
        for (int i = 0; i < nums.size(); ++i) {
            numIndices[nums[i]].push_back(i);
        }
        int result = 0;
        for (auto [_, indices] : numIndices) {
            for (int i = 0; i < indices.size() - 1; ++i) {
                for (int j = i + 1; j < indices.size(); ++j) {
                    if ((indices[i] * indices[j]) % k == 0) {
                        ++result;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {3,1,2,2,2,1,3};
    cout << solution.countPairs(nums, 2) << endl; // 4
}