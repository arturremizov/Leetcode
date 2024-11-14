#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        int result = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canDistribute(mid, n, quantities)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
private: 
    bool canDistribute(int amount, int n, vector<int>& quantities) {
        int stores = 0;
        for (int quantity : quantities) {
            stores += ceil(quantity / (float)amount);
        }
        return stores <= n;
    }
};

int main() {
    Solution solution; 
    vector<int> quantities = {11,6};
    cout << solution.minimizedMaximum(6,quantities) << endl; // 3
}