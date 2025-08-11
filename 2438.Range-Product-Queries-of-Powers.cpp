#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9+7;
        vector<int> powers;
        int num = 1;
        while (n) {
            if (n % 2 == 1) {
                powers.push_back(num);
            }
            n /= 2;
            num *= 2;
        }
        vector<int> result;
        for (auto& query : queries) {
            int start = query[0], end = query[1];
            long long current = 1;
            for (int i = start; i <= end; ++i) {
                current = (current * powers[i]) % MOD;
            }
            result.push_back(current);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> queries = {{0,1},{2,2},{0,3}};
    vector<int> result = solution.productQueries(15,queries); // [2,4,64]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}