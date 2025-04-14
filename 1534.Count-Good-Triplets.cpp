#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        const int n = arr.size();
        int result = 0;
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (abs(arr[i] - arr[j]) <= a && 
                        abs(arr[j] - arr[k]) <= b && 
                        abs(arr[i] - arr[k]) <= c) {
                        ++result;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> arr = {3,0,1,1,9,7};
    cout << solution.countGoodTriplets(arr, 7, 2, 3) << endl; // 4
}