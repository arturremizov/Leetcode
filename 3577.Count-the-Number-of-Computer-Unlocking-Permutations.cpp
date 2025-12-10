#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        if (*min_element(complexity.begin() + 1, complexity.end()) <= complexity[0]) {
            return 0;
        } 
        const int MOD = 1e9+7;
        int result = 1;
        for (int i = 2; i < complexity.size(); ++i) {
            result = (1LL * result * i) % MOD;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> complexity = {1,2,3};
    cout << solution.countPermutations(complexity) << endl; // 2
}