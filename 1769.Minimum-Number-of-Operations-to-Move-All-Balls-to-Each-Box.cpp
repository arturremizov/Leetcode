#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        const int n = boxes.length();
        vector<int> result(n);
        int balls = 0, moves = 0;
        for (int i = 0; i < n; ++i) {
            result[i] = balls + moves;
            moves += balls;
            balls += (boxes[i] - '0');
        }
        balls = 0, moves = 0;
        for (int i = n - 1; i >= 0; --i) {
            result[i] += balls + moves;
            moves += balls;
            balls += (boxes[i] - '0');
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> result = solution.minOperations("001011"); // [11,8,5,4,3,4]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}