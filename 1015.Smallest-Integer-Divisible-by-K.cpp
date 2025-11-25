#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0) return -1;
        int result = 1;
        int curNum = 1;
        unordered_set<int> visited;
        while (curNum % k) {
            if (visited.count(curNum)) return -1;
            visited.insert(curNum);
            curNum = ((curNum * 10) + 1) % k;
            ++result;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.smallestRepunitDivByK(3) << endl; // 3
}