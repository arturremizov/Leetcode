#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        unordered_map<int, int> memo;
        return dpMemo(n, memo);
    }
private:
    int dpMemo(int n, unordered_map<int, int>& memo) {
        if (memo.count(n)) return memo[n];
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        memo[n] = dpMemo(n - 3, memo) + dpMemo(n - 2, memo) + dpMemo(n - 1, memo);
        return memo[n];
    }
};

int main() 
{
    Solution solution; 
    cout << solution.tribonacci(4) << endl; // 4
    cout << solution.tribonacci(25) << endl; // 1389537
    cout << solution.tribonacci(35) << endl; // 615693474
}