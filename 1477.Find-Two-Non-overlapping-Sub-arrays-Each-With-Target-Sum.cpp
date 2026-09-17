#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        const int n = arr.size();

        vector<int> endIndex(n, -1);
        int sum = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                ++left;
            }
            if (sum == target && left <= right) {
                endIndex[left] = right;
            }
        }

        vector<int> bestLengthFrom(n + 1, INT_MAX);
        for (int i = n - 1; i >= 0; --i) {
            bestLengthFrom[i] = bestLengthFrom[i + 1];
            if (endIndex[i] == -1) continue;
            int length = endIndex[i] - i + 1;
            bestLengthFrom[i] = min(bestLengthFrom[i], length); 
        }

        int result = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (endIndex[i] == -1) continue;
            int firstLength = endIndex[i] - i + 1;
            int secondLenth = bestLengthFrom[endIndex[i] + 1];
            if (secondLenth != INT_MAX) {
                result = min(result, firstLength + secondLenth);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};

int main() {
    Solution solution; 
    vector<int> arr = {7,3,4,7};
    cout << solution.minSumOfLengths(arr, 7) << endl; // 2
}