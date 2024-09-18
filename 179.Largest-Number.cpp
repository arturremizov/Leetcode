#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStrings;
        for (int num : nums) {
            numStrings.push_back(to_string(num));
        }
        sort(numStrings.begin(), numStrings.end(), [] (const auto& lhs, const auto& rhs) {
            return lhs + rhs > rhs + lhs;
        });

        if (numStrings.front() == "0") return "0";

        string result;
        for (string num : numStrings) {
            result += num;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {3,30,34,5,9};
    cout << solution.largestNumber(nums) << endl; // 9534330
}