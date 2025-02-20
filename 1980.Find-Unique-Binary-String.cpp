#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        const int n = nums.size();
        string result(n, '0');
        unordered_set<string> stringSet(nums.begin(), nums.end());
        return backtrack(0, result, n, stringSet);
    }
private:
    string backtrack(int i, string current, int n, unordered_set<string>& stringSet) {
        if (i == n) {
            return !stringSet.count(current) ? current : "";
        }

        string result = backtrack(i + 1, current, n, stringSet);
        if (!result.empty()) return result;

        current[i] = '1';
        result = backtrack(i + 1, current, n, stringSet);
        if (!result.empty()) return result;

        return "";
    }
};

int main() {
    Solution solution; 
    vector<string> nums = {"01","10"};
    cout << solution.findDifferentBinaryString(nums) << endl; // "00"
}