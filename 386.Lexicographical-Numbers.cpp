#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i < 10; i++) {
            dfs(n, i, result);
        }
        return result;
    }
private:
    void dfs(int n, int current, vector<int>& result) {
        if (current > n) return;
        result.push_back(current);
        current *= 10;
        for (int i = 0; i < 10; i++) {
            dfs(n, current + i, result);
        }
    }
};

int main() {
    Solution solution; 
    vector<int> result = solution.lexicalOrder(13); // [1,10,11,12,13,2,3,4,5,6,7,8,9]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}