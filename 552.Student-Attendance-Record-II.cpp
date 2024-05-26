#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    const int MOD = 1000000007;
    int checkRecord(int n) {
        if (n == 1) {
            return 3;
        }
        vector<vector<int>> temp = {
                {1, 1, 0}, 
                {1, 0, 0}, 
        };
        for (int i = 0; i < n - 1; ++i) {
            vector<vector<int>> result(2, vector<int>(3));
            // Choose P
            result[0][0] = ((temp[0][0] + temp[0][1]) % MOD + temp[0][2]) % MOD;
            result[1][0] = ((temp[1][0] + temp[1][1]) % MOD + temp[1][2]) % MOD;
            // Choose L
            result[0][1] = temp[0][0];
            result[1][1] = temp[1][0];
            result[0][2] = temp[0][1];
            result[1][2] = temp[1][1];
            // Chose A 
            result[1][0] = (result[1][0] + (((temp[0][0] + temp[0][1]) % MOD + temp[0][2]) % MOD)) % MOD;
            temp = result;
        }
        // unordered_map<int, vector<vector<int>>> cache;
        // vector<vector<int>> result = count(n, cache);
        int result_value = 0;
        for (int row = 0; row < temp.size(); ++row) {
            for (int col = 0; col < temp[row].size(); ++col) {
                result_value = (result_value + temp[row][col]) % MOD;                                         
            }
        }
        return result_value;
    }
private:
    vector<vector<int>> count(int n, unordered_map<int, vector<vector<int>>>& cache) {
        if (cache.count(n)) return cache[n];
        if (n == 1) {
            return {
                {1, 1, 0}, 
                {1, 0, 0}, 
            };
        }
        vector<vector<int>> temp = count(n - 1, cache);
        vector<vector<int>> result(2, vector<int>(3));
        // Choose P
        result[0][0] = ((temp[0][0] + temp[0][1]) % MOD + temp[0][2]) % MOD;
        result[1][0] = ((temp[1][0] + temp[1][1]) % MOD + temp[1][2]) % MOD;
        // Choose L
        result[0][1] = temp[0][0];
        result[1][1] = temp[1][0];
        result[0][2] = temp[0][1];
        result[1][2] = temp[1][1];
        // Chose A 
        result[1][0] = (result[1][0] + (((temp[0][0] + temp[0][1]) % MOD + temp[0][2]) % MOD)) % MOD;
        cache[n] = result;
        return cache[n];
    }
};

int main() 
{
    Solution solution; 
    cout << solution.checkRecord(2) << endl; // 8
    cout << solution.checkRecord(1) << endl; // 3
    cout << solution.checkRecord(10101) << endl; // 183236316
}