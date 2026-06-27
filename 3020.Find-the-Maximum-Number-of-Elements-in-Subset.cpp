#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int result = 0;
        if (freq[1] % 2 == 1) {
            result = freq[1];
        } else {
            result = freq[1] > 0 ? freq[1] - 1 : 0;
        }
        for (auto [num, _] : freq) {
            if (num == 1) continue;
            unsigned int cur = num;
            int length = 0;
            while (freq.count(cur) && freq[cur] > 1) {
                cur *= cur;
                length += 2;
            }
            result = max(result, length + (freq.count(cur) ? 1 : -1));
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,16,49,16,121};
    cout << solution.maximumLength(nums) << endl; // 3
}