#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int result = 0;
        vector<vector<int>> patterns = {{0,0}, {1,0}, {0,1}, {1,1}};
        for (vector<int>& pattern : patterns) {
            int count = 0;
            for (int num : nums) {
                if (num % 2 == pattern[count % 2]) {
                    ++count;
                }
            }
            result = max(result, count);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,3,4};
    cout << solution.maximumLength(nums) << endl; // 4
}