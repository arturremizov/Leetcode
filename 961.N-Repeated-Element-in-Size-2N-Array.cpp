#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> elements;
        for (int num : nums) {
            if (elements.count(num)) return num;
            elements.insert(num);
        }
        return -1;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {5,1,5,2,5,3,5,4};
    cout << solution.repeatedNTimes(nums) << endl; // 5
}