#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int,int> productCount;
        unordered_map<int,int> pairCount;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int product = nums[i] * nums[j];
                pairCount[product] += productCount[product];
                productCount[product]++;
            }
        }
        int result = 0;
        for (auto [_, count] : pairCount) {
            result += 8 * count;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {2,3,4,6};
    cout << solution.tupleSameProduct(nums) << endl; // 8
}