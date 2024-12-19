#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int currentMax = -1;
        int result = 0;
        for (int i = 0; i < arr.size(); ++i) {
            currentMax = max(currentMax, arr[i]);
            if (currentMax == i) {
                ++result;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> arr = {4,3,2,1,0};
    cout << solution.maxChunksToSorted(arr) << endl; // 1
}