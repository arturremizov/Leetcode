#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1 = splitString(sentence1);
        vector<string> s2 = splitString(sentence2);

        if (s1.size() > s2.size()) {
            swap(s1, s2);
        }
        int left1 = 0, left2 = 0;
        while (left1 < s1.size()  && s1[left1] == s2[left2]) {
            ++left1, ++left2;
        }

        int right1 = s1.size() - 1, right2 = s2.size() - 1;
        while (right1 >= 0 && right2 >= 0 && s1[right1] == s2[right2]) {
            --right1, --right2;
        }

        return left1 > right1;
    }
private:
    vector<string> splitString(string str) {
        stringstream stream(str);
        string word;
        vector<string> result;
        while (stream >> word) {
            result.push_back(word);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.areSentencesSimilar("My name is Haley", "My Haley") << endl; // true
}