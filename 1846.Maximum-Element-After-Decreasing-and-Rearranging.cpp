#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int curNum = 1;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] - curNum <= 1) {
                curNum = arr[i];
            } else {
                ++curNum;
            }
        }
        return curNum;
    }
};

int main() {
    Solution solution; 
    vector<int> arr = {45,30,87,29};
    cout << solution.maximumElementAfterDecrementingAndRearranging(arr) << endl; // 4
}