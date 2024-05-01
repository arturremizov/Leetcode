#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int left = 0;
        for (int right = 0; right < word.length(); ++right) {
            if (word[right] == ch) {
                while (left < right) {
                    swap(word[left], word[right]); 
                    ++left, --right;                              
                }
                break;
            }
        }
        return word;
    }
};

int main() 
{
    Solution solution; 
    cout << solution.reversePrefix("abcdefd", 'd') << endl; // dcbaefd
    cout << solution.reversePrefix("xyxzxe", 'z') << endl; // zxyxxe
    cout << solution.reversePrefix("abcd", 'z') << endl; // abcd
}