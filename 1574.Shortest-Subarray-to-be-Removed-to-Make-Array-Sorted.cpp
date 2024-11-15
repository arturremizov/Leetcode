#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        const int n = arr.size();

        int right = n - 1;
        while (right > 0 && arr[right - 1] <= arr[right]) {
            --right;
        }

        int result = right;

        int left = 0;
        while (left < n - 1 && arr[left] <= arr[left + 1]) {
            ++left;
        }

        result = min(result, n - 1 - left);

        left = 0, right = n - 1;
        while (left < right) {
            while (right < n && left + 1 < right && arr[right - 1] <= arr[right] && arr[left] <= arr[right]) {
                --right;
            }
            while (right < n && arr[left] > arr[right]) {
                ++right;
            }
            result = min(result, right - left - 1);
            if (arr[left] > arr[left + 1]) break;
            ++left;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> arr = {1,2,3,10,4,2,3,5};
    cout << solution.findLengthOfShortestSubarray(arr) << endl; // 3
}