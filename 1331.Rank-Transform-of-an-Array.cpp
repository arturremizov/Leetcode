#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums(arr.begin(), arr.end());
        sort(nums.begin(), nums.end());

        unordered_map<int, int> map;
        int rank = 1;
        for (int num : nums) {
            if (map.count(num)) continue;
            map[num] = rank;
            ++rank;
        }

        vector<int> result;
        for (int num : arr) {
            result.push_back(map[num]);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> arr = {40,10,20,30};
    vector<int> result = solution.arrayRankTransform(arr); // [4,1,2,3]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}