#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> digitsCount(10);
        for (int digit : digits) {
            digitsCount[digit]++;
        }
        vector<int> result;
        for (int i = 0; i < 10; ++i) {
            if (i == 0 || digitsCount[i] == 0) continue;
            digitsCount[i]--;
            for (int j = 0; j < 10; ++j) {
                if (digitsCount[j] == 0) continue;
                digitsCount[j]--;
                for (int k = 0; k < 10; k+=2) {
                    if (digitsCount[k] == 0) continue;
                    int num = i * 100 + j * 10 + k;
                    result.push_back(num);
                }
                digitsCount[j]++;
            }
            digitsCount[i]++;
        }
        return result;
    }
};
 
int main() {
    Solution solution; 
    vector<int> digits = {2,1,3,0};
    vector<int> result = solution.findEvenNumbers(digits); //[102,120,130,132,210,230,302,310,312,320]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}