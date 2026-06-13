#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;
        for (string& word : words) {
            int weight = 0;
            for (char c : word) {
                weight += weights[c - 'a'];
            }
            char newChar = 'z' - (weight % 26);
            result += newChar;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<string> words = {"abcd","def","xyz"};
    vector<int> weights = {5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2};
    cout << solution.mapWordWeights(words, weights) << endl; // "rij"
}