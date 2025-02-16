#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(n * 2 - 1);
        unordered_set<int> used;
        backtrack(0, n, result, used);
        return result;
    }
private:
    bool backtrack(int i, int n, vector<int>& result, unordered_set<int>& used) {
        if (result.size() == i) return true;

        for (int num = n; num > 0; --num) {
            if (used.count(num)) continue;
            if (num > 1 && (i + num >= result.size() || result[i + num] != 0)) continue;

            used.insert(num);
            result[i] = num;
            if (num > 1) {
                result[i + num] = num;
            }
            
            int j = i + 1;
            while (j < result.size() && result[j] != 0) {
                ++j;
            }
            
            if (backtrack(j, n, result, used)) {
                return true;
            } else {
                used.erase(num);
                result[i] = 0;
                if (num > 1) {
                    result[i + num] = 0;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution; 
    vector<int> result = solution.constructDistancedSequence(3); // [3,1,2,3,2]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}