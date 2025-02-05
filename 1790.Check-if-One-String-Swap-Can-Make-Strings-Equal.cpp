#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        const int n = s1.length();

        vector<int> indices;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                indices.push_back(i);
            }
            if (indices.size() > 2) return false; 
        }

        if (indices.size() == 2) {
            int i = indices[0], j = indices[1];
            if (s1[i] == s2[j] && s1[j] == s2[i]) {
                return true;
            } 
            return false;
        }
        return indices.size() == 0;
    }
};

int main() {
    Solution solution; 
    cout << solution.areAlmostEqual("bank","kanb") << endl; // true
}