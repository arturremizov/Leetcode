#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> prev;
        for (int num : arr) {
            unordered_set<int> current {num};
            for (int prevNum : prev) {
                current.insert(num | prevNum);
            }
            result.insert(current.begin(), current.end());
            prev = current;
        }
        return result.size();
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {1,2,4};
    cout << solution.subarrayBitwiseORs(nums) << endl; // 6
}