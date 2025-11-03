#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        const int n = colors.length();
        int result = 0;
        int left = 0;
        for (int right = 1; right < n; ++right) {
            if (colors[left] == colors[right]) {
                if (neededTime[left] < neededTime[right]) {
                    result += neededTime[left];
                    left = right;
                } else {
                    result += neededTime[right];
                }
            } else {
                left = right;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> neededTime = {1,2,3,4,5};
    cout << solution.minCost("abaac",neededTime) << endl; // 3
}