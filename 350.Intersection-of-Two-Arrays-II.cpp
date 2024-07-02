#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        for (int num : nums1) {
            count[num]++;
        }
        vector<int> result;
        for (int num : nums2) {
            if (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }
        return result;
    }
};
 
int main() 
{
    Solution solution; 
    vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
    vector<int> result = solution.intersect(nums1, nums2); // [2,2]
   
    for (int num : result) {
        cout << num << ",";
    }
}
