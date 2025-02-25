#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int currentSum = 0;
        int oddCount = 0;
        int evenCount = 0;
        int result = 0;
        for (int num : arr) {
            currentSum += num;
            if (currentSum % 2 == 1) {
                result = (result + 1 + evenCount) % MOD;
                ++oddCount;
            } else {
                result = (result + oddCount) % MOD;
                ++evenCount;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> arr = {1,3,5};
    cout << solution.numOfSubarrays(arr) << endl; // 4
}