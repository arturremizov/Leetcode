#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        const int n = spells.size();
        sort(potions.begin(), potions.end());
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = binarySearch(success, spells[i], potions);
        }
        return result;
    }
private:
    int binarySearch(long long value, int multiplier, vector<int>& potions) {
        const int m = potions.size();
        int left = 0, right = m - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if ((long long)potions[mid] * multiplier < value) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return m - left;
    }
};

int main() {
    Solution solution; 
    vector<int> spells = {5,1,3};
    vector<int> potions = {1,2,3,4,5};
    vector<int> result = solution.successfulPairs(spells,potions,7); // [4,0,3]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}