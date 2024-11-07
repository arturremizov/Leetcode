#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> count(32);
        for (int num : candidates) {
            int i = 0;
            while (num > 0) {
                count[i] += num & 1;
                num = num >> 1;
                ++i;
            }
        }
        return *max_element(count.begin(), count.end());
    }
};

int main() {
    Solution solution; 
    vector<int> candidates = {16,17,71,62,12,24,14};
    cout << solution.largestCombination(candidates) << endl; // 4
}