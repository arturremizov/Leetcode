#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int n = A.size();
        vector<int> numCount(n + 1);
        int count = 0;
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            int num1 = A[i], num2 = B[i];
            numCount[num1]++;
            if (numCount[num1] == 2) {
                ++count;
            }
            numCount[num2]++;
            if (numCount[num2] == 2) {
                ++count;
            }
            result[i] = count;
        } 
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> A = {1,3,2,4};
    vector<int> B = {3,1,2,4};
    vector<int> result = solution.findThePrefixCommonArray(A,B); //[[0,2,3,4]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}