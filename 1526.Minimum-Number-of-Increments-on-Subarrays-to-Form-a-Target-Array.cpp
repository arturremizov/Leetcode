#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        const int n = target.size();
        int result = target[0];
        for (int i = 1; i < n; ++i) {
            if (target[i] > target[i - 1]) {
                result += target[i] - target[i - 1];
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> target = {1,2,3,2,1};
    cout << solution.minNumberOperations(target) << endl; // 3
}