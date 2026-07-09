#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n,
                                      vector<int>& nums, 
                                      int maxDiff, 
                                      vector<vector<int>>& queries) {
        
        vector<int> components(n);
        int componentsCount = 0;
        for (int i = 1; i < n; ++i) {
            if (abs(nums[i] - nums[i - 1]) > maxDiff) {
                ++componentsCount;
            }
            components[i] = componentsCount;
        }
        vector<bool> result;
        for (auto& query : queries) {
            bool isConnected = components[query[0]] == components[query[1]];
            result.push_back(isConnected);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {2,5,6,8};
    vector<vector<int>> queries = {{0,1},{0,2},{1,3},{2,3}};
    vector<bool> result = solution.pathExistenceQueries(4,nums,2,queries); // [false,false,true,true]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}