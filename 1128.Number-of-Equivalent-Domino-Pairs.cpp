#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int result = 0;
        unordered_map<int,int> pairs;
        for (vector<int> domino : dominoes) {
            int key = 0;
            if (domino[0] < domino[1]) {
                key = domino[0] * 10 + domino[1];
            } else {
                key = domino[1] * 10 + domino[0];
            }
            result += pairs[key];
            pairs[key]++;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> dominoes = {{1,2}, {2,1}, {3,4}, {5,6}};
    cout << solution.numEquivDominoPairs(dominoes) << endl; // 1
}
 