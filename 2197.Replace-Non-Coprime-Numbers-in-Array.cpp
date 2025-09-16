#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;
        for (int num : nums) {
            result.push_back(num);
            while (result.size() >= 2) {
                int x = result[result.size() - 1];
                int y = result[result.size() - 2];
                int commonDivisor = gcd(x, y);
                if (commonDivisor == 1) break; 
                result.pop_back();
                result.pop_back();
                result.push_back(lcm(x, y));
            }
        }
        return result;
    }    
};

int main() {
    Solution solution; 
    vector<int> nums = {6,4,3,2,7,6,2};
    vector<int> result = solution.replaceNonCoprimes(nums); // [12,7,6]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}