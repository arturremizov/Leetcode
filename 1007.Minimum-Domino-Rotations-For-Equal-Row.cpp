#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result1 = rotate(tops[0], tops, bottoms);
        if (tops[0] == bottoms[0]) return result1;
        int result2 = rotate(bottoms[0], tops, bottoms);
        if (result1 == -1) return result2;
        if (result2 == -1) return result1;
        return min(result1, result2);
    }
private:
    int rotate(int target, vector<int>& tops, vector<int>& bottoms) {
        int rotateTop = 0, rotateBottom = 0;
        for (int i = 0; i < tops.size(); ++i) {
            if (tops[i] != target && bottoms[i] != target) {
                return -1;
            } else if (tops[i] != target) {
                ++rotateTop;
            } else if (bottoms[i] != target) {
                ++rotateBottom;
            }
        }
        return min(rotateTop, rotateBottom);
    }
};

int main() {
    Solution solution; 
    vector<int> tops = {2,1,2,4,2,2};
    vector<int> bottoms = {5,2,6,2,3,2};
    cout << solution.minDominoRotations(tops, bottoms) << endl; // 2
}
 