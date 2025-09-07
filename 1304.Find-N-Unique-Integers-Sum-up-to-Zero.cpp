#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        for (int num = 1; num <= n / 2; ++num) {
            result.push_back(num);
            result.push_back(-num);
        }
        if (n % 2 == 1) result.push_back(0);
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> result = solution.sumZero(5); // [1,-1,2,-2,0]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}