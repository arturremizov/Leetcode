#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c0 = 0, c1 = 0, c2 = 0;
        for (int stone : stones) {
            if (stone % 3 == 0) {
                c0++;
            } else if (stone % 3 == 1) {
                c1++;
            } if (stone % 3 == 2) {
                c2++;
            }
        }
        if (c0 % 2 == 0) {
            return c1 > 0 && c2 > 0;
        }
        return abs(c1 - c2) >= 3;
    }
};

int main() {
    Solution solution;
    vector<int> stones = {5,1,2,4,3};
    cout << solution.stoneGameIX(stones) << endl; // false
}