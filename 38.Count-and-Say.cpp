#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 1; i < n; ++i) {
            string current;
            int count = 1;
            for (int j = 1; j < result.length(); ++j) {
                if (result[j] == result[j - 1]) {
                    ++count;
                } else {
                    current += to_string(count);
                    current += result[j - 1];
                    count = 1;
                }
            }
            current += to_string(count);
            current += result.back();
            result = current;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.countAndSay(4) << endl; // 1211
}