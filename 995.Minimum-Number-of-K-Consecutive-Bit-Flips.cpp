#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        const int n = nums.size();
        queue<int> queue;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            while (!queue.empty() && i > queue.front() + k - 1) {
                queue.pop();
            }

            if ((nums[i] + queue.size()) % 2 == 0) {
                if (i + k > n) return -1;
                ++result;
                queue.push(i);
            }
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums1 = {0,1,0};
    cout << solution.minKBitFlips(nums1, 1) << endl; // 2
    vector<int> nums2 = {1,1,0};
    cout << solution.minKBitFlips(nums2, 2) << endl; // -1
}