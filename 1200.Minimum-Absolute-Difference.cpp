#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        const int n = arr.size();
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        for (int i = 1; i < n; ++i) {
            minDiff = min(minDiff, abs(arr[i] - arr[i - 1]));
        }

        vector<vector<int>> result;
        for (int i = 1; i < n; ++i) {
            if (minDiff == abs(arr[i] - arr[i - 1])) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> arr = {4,2,1,3};
    vector<vector<int>> result = solution.minimumAbsDifference(arr); // [[1,2],[2,3],[3,4]]
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]\n";
    }
}