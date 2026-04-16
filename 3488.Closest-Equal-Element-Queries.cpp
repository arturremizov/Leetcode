#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        const int n = nums.size();
        unordered_map<int, vector<int>> numToIndices;
        for (int i = 0; i < n; ++i) {
            numToIndices[nums[i]].push_back(i);
        }
        vector<int> result;
        for (int query : queries) {
            int num = nums[query];
            vector<int>& indices = numToIndices[num];
            if (indices.size() < 2) {
                result.push_back(-1);
                continue;
            } 
            int index = lower_bound(indices.begin(), indices.end(), query) - indices.begin();
            int distance = INT_MAX;
            if (index > 0) {
                distance = query - indices[index - 1];
            } else {
                distance = min(distance, n - (indices.back() - query));
            }

            if (index + 1 < indices.size()) {
                distance = min(distance, indices[index + 1] - query);
            } else {
                distance = min(distance, n - (query - indices[0]));
            }

            result.push_back(distance);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,3,1,4,1,3,2};
    vector<int> queries = {0,3,5};
    vector<int> result = solution.solveQueries(nums, queries); // [2,-1,3]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}