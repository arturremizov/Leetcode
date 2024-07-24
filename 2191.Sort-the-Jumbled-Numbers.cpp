#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        const int n = nums.size();
        vector<pair<int, int>> pairs; // mapped num, index
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int mappedNum = 0;
            if (num == 0) {
                mappedNum = mapping[num];
            }
            int base = 1;
            while (num) {
                int digit = num % 10;
                num /= 10;

                mappedNum += base * mapping[digit];
                base *= 10;
            }
             pairs.push_back({mappedNum, i});
        }
        
        sort(pairs.begin(), pairs.end());

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int numIndex = pairs[i].second;
            result[i] = nums[numIndex];
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> mapping = {8,9,4,0,2,1,3,5,7,6};
    vector<int> nums = {991,338,38};
    vector<int> result = solution.sortJumbled(mapping, nums); // [338,38,991]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}