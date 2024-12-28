#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> kSums = { accumulate(nums.begin(), nums.begin() + k, 0) };
        for (int i = k; i < nums.size(); ++i) {
            kSums.push_back(kSums.back() + nums[i] - nums[i - k]);
        }
        unordered_map<string, int> cache;
        return getIndicies(nums, k, kSums, cache);
    }
private:
    int getMaxSum(int i, int count, vector<int>& nums, int k, vector<int>& kSums, unordered_map<string, int>& cache) {
        string key = to_string(i) + "," + to_string(count);
        if (cache.count(key)) return cache[key];

        if (count == 3 || i > nums.size() - k) {
            return 0;
        } 
        // include
        int include = kSums[i] + getMaxSum(i + k, count + 1, nums, k, kSums, cache);
        //skip
        int skip = getMaxSum(i + 1, count, nums, k, kSums, cache);
        cache[key] = max(include, skip);
        return cache[key];
    }

    vector<int> getIndicies(vector<int>& nums, int k, vector<int>& kSums, unordered_map<string, int>& cache) {
        int i = 0;
        vector<int> indices;
        while (i <= nums.size() - k && indices.size() < 3) {
            int include = kSums[i] + getMaxSum(i + k, indices.size() + 1, nums, k, kSums, cache);
            int skip = getMaxSum(i + 1, indices.size(), nums, k, kSums, cache);

            if (include >= skip) {
                indices.push_back(i);
                i += k;
            } else {
                ++i;
            }
        }
        return indices;
    }
}; 

int main() {
    Solution solution; 
    vector<int> nums = {1,2,1,2,6,7,5,1};
    vector<int> result = solution.maxSumOfThreeSubarrays(nums, 2); //[0,3,5]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}