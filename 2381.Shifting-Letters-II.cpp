#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        const int n = s.length();
        vector<int> prefixDiff(n + 1);
        for (auto shift : shifts) {
            int left = shift[0], right = shift[1], diff = shift[2];
            prefixDiff[right + 1] += (diff == 1 ? 1 : -1);
            prefixDiff[left] += (diff == 1 ? -1 : 1);
        }
        
        int difference = 0;
        for (int i = n; i > 0; --i) {
            difference += prefixDiff[i];
            int asciiValue = (s[i - 1] - 'a' + difference) % 26;
            if (asciiValue < 0) asciiValue += 26;  
            s[i - 1] = char(asciiValue + 'a');
        }
        return s;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> shifts = {{0,1,0},{1,2,1},{0,2,1}};
    cout << solution.shiftingLetters("abc", shifts) << endl; // "ace"
}