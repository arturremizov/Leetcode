#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> splits;
        for (int i = 0; i < weights.size() - 1; ++i) {
            splits.push_back(weights[i] + weights[i + 1]);
        }
        sort(splits.begin(), splits.end());
        long long result = 0;
        int left = 0;
        int right = splits.size() - 1;
        while (k > 1) {
            result += splits[right] - splits[left];
            ++left, --right, --k;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> weights = {1,3,5,1};
    cout << solution.putMarbles(weights, 2) << endl; // 4
}