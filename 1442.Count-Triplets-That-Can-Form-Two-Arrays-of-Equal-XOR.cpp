#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        const int n = arr.size();
        int result = 0;
        for (int i = 0; i < n-1; ++i) {
            int a = 0;
            for (int j = i+1; j < n; ++j) {
                a ^= arr[j-1];
                int b = 0;                
                for (int k = j; k < n; ++k) {
                    b ^= arr[k];
                    if (a == b) {
                        ++result;
                    } 
                }
            }
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> arr = {2,3,1,6,7};
    cout << solution.countTriplets(arr) << endl; // 4
    vector<int> arr2 = {1,1,1,1,1};
    cout << solution.countTriplets(arr2) << endl; // 10
}