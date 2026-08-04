#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        auto [minNum, maxNum] = minmax_element(nums.begin(), nums.end());
        unordered_set<int> numsSet(nums.begin(), nums.end());
        vector<int> result;
        for (int num = *minNum + 1; num < *maxNum; ++num) {
            if (numsSet.count(num)) continue;
            result.push_back(num);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,4,2,5};
    vector<int> result = solution.findMissingElements(nums); // [3]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}