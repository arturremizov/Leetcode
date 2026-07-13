#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> queue({1,2,3,4,5,6,7,8,9});
        vector<int> result;
        while (!queue.empty()) {
            int num = queue.front();
            queue.pop();
            if (low <= num && num <= high) {
                result.push_back(num);
            }
            int prev = num % 10;
            if (prev == 9) continue;
            int nextNum = num * 10 + (prev + 1);
            if (nextNum <= high) {
                queue.push(nextNum);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> result = solution.sequentialDigits(100, 300); // [123,234]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}