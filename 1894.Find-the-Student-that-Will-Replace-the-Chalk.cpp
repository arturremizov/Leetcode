#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum = 0;
        for (int c : chalk) {
            sum += c;
            if (sum > k) break;
        }

        k = k % sum;
        for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i]) return i;
            k -= chalk[i];
        }
        return 0;
    }
};

int main() {
    Solution solution; 
    vector<int> chalk = {3,4,1,2};
    cout << solution.chalkReplacer(chalk, 25) << endl; // 1
}