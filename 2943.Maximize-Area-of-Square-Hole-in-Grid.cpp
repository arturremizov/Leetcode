#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxH = longestConsecutive(hBars);
        int maxV = longestConsecutive(vBars);
        int side = min(maxH, maxV);
        return side * side;
    }
private: 
    int longestConsecutive(vector<int>& bars) {
        sort(bars.begin(), bars.end());
        int longest = 1, current = 1;
        for (int i = 1; i < bars.size(); ++i) {
            if (bars[i - 1] + 1 == bars[i]) {
                current++;
            } else {
                current = 1;
            }
            longest = max(longest, current);
        }
        return longest + 1;
    }
};

int main() {
    Solution solution; 
    vector<int> hBars = {2,3};
    vector<int> vBars = {2,4};
    cout << solution.maximizeSquareHoleArea(2,3,hBars,vBars) << endl; // 4
}