#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int i = 0;
        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left]);
                ++left;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                --right;
                --i;
            }
            ++i;
        }
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums = {2,0,2,1,1,0};
    solution.sortColors(nums); //[0,0,1,1,2,2]
    cout << "[";
    for (int i = 0; i < nums.size(); ++i) { 
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << ",";
        }
    }
    cout << "]\n";
}