#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        const int n = code.size();
        vector<int> result(n);
        if (k == 0) return result;
        int left = 0;
        int currentSum = 0;
        for (int right = 0; right < n + abs(k); ++right) {
            currentSum += code[right % n];
            if (right - left + 1 > abs(k)) {
                currentSum -= code[left % n];
                left = (left + 1) % n;
            }

            if (right - left + 1 == abs(k)) {
                if (k > 0) {
                    result[(left + n - 1) % n] = currentSum;
                } else if (k < 0) {
                    result[(right + 1) % n] = currentSum;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> code = {5,7,1,4};
    vector<int> result = solution.decrypt(code, 3); // [12,10,16,13]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}