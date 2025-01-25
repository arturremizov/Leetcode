#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        vector<queue<int>> groups;
        unordered_map<int, int> numToGroup;
        for (int num : sortedNums) {
            if (groups.empty() || abs(num - groups.back().back()) > limit) {
                groups.push_back(queue<int>());
            }
            groups.back().push(num);
            numToGroup[num] = groups.size() - 1;
        }

        vector<int> result;
        for (int num : nums) {
            int groupIndex = numToGroup[num];
            result.push_back(groups[groupIndex].front());
            groups[groupIndex].pop();
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums = {1,5,3,9,8};
    vector<int> result = solution.lexicographicallySmallestArray(nums, 2); //[1,3,5,8,9]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}