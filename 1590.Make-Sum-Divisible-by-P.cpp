#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = reduce(nums.begin(), nums.end(), 0LL); 
        int remainder = total % p;
        if (remainder == 0) return 0;

        const int n = nums.size();
        int result = n;
        int currentSum = 0;
        unordered_map<int, int> remainderToIndex = {
            {0,-1}
        };
        for (int i = 0; i < n; ++i) {
            currentSum = (nums[i] + currentSum) % p;
            int prefix = (currentSum - remainder + p) % p;
            if (remainderToIndex.count(prefix)) {
                int length = i - remainderToIndex[prefix];
                result = min(result, length);
            }
            remainderToIndex[currentSum] = i;
        }
        return result == n ? -1 : result;
    }
};

int main() {
    Solution solution; 
    vector<int> arr = {3,1,4,2};
    cout << solution.minSubarray(arr, 6) << endl; // 1
}