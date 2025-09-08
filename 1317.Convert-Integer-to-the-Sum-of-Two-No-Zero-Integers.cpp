#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i <= n; ++i) {
            if (to_string(i).find('0') == string::npos && 
                to_string(n - i).find('0') == string::npos) {

                return {i, n - i};
            }
        }
        return {};
    }
};

int main() {
    Solution solution; 
    vector<int> result = solution.getNoZeroIntegers(11); // [2,9]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}