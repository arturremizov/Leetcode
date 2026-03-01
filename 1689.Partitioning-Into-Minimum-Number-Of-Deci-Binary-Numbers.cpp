#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int result = 0;
        for (int c : n) {
            result = max(result, c - '0');
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.minPartitions("82734") << endl; // 8
}