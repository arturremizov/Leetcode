#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        const int n = num.length();
        string result;
        for (int i = 0; i < n - 2; ++i) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                if (!result.empty() && result[0] > num[i]) continue;
                result = num.substr(i, 3);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.largestGoodInteger("6777133339") << endl; // "777"
}