#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (count[a] == count[b]) return a > b;
            return count[a] < count[b];
        }); 
        return nums;
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums = {2,3,1,3,2};
    vector<int> result = solution.frequencySort(nums); // [1,3,3,2,2]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}