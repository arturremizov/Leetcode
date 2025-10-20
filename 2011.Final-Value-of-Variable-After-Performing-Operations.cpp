#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int result = 0;
        for (string& operation : operations) {
            if (operation == "++X" || operation == "X++") {
                ++result;
            } else {
                --result;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<string> operations = {"--X","X++","X++"};
    cout << solution.finalValueAfterOperations(operations) << endl; // 1
}