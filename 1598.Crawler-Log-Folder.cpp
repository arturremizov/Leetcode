#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int result = 0;
        for (string log : logs) {
            if (log == "./") continue;
            if (log == "../") {
                result = max(0, result - 1);
            } else {
                ++result;
            }
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<string> logs = {"d1/","d2/","../","d21/","./"};
    cout << solution.minOperations(logs) << endl; // 2
    vector<string> logs2 = {"d1/","d2/","./","d3/","../","d31/"};
    cout << solution.minOperations(logs2) << endl; // 3
}
