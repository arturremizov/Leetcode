#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        int maxFreq = 0;
        for (int num : nums) {
            freqMap[num]++;
            maxFreq = max(maxFreq, freqMap[num]);
        }
        int result = 0;
        for (auto [_, freq] : freqMap) {
            if (freq != maxFreq) continue;
            result += freq;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums1 = {1,2,2,3,1,4};
    cout << solution.maxFrequencyElements(nums1) << endl; // 4
}
