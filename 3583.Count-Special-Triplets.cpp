#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> nextNumCount;
        for (int num : nums) {
            nextNumCount[num]++;
        }
        
        int result = 0;
        unordered_map<int, int> prevNumCount;
        for (int num : nums) {
            nextNumCount[num]--;
            result = (result + 1LL * prevNumCount[num * 2] * nextNumCount[num * 2]) % MOD;
            prevNumCount[num]++;
        }    
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {8,4,2,8,4};
    cout << solution.specialTriplets(nums) << endl; // 2
}