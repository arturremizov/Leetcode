#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> charCount(26);
        for (char c : text) {
            charCount[indexFor(c)]++;
        }        
        return min({
            charCount[indexFor('b')],       // b
            charCount[indexFor('a')],       // a
            charCount[indexFor('l')] / 2,   // l x 2
            charCount[indexFor('o')] / 2,   // o x 2
            charCount[indexFor('n')],       // n
        });
    }
private:
    int indexFor(char c) {
        return c - 'a';
    }
};

int main() {
    Solution solution; 
    cout << solution.maxNumberOfBalloons("loonbalxballpoon") << endl; // 2
}