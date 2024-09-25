#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    struct PrefixNode {
        PrefixNode* children[26] = { nullptr };
        int count = 0;
    };
    

    class PrefixTree {
        PrefixNode* root;
    public:
        PrefixTree() {
            root = new PrefixNode();
        }

        void insert(const string& word) {
            PrefixNode *currentNode = root;
            for (char c : word) {
                int index = c - 'a';
                if (!currentNode->children[index]) {
                    currentNode->children[index] = new PrefixNode();
                }
                currentNode = currentNode->children[index];
                currentNode->count++;
            }
        }

        int getScore(const string& word) {
            PrefixNode *currentNode = root;
            int score = 0;
            for (char c : word) {
                int index = c - 'a';
                currentNode = currentNode->children[index];
                score += currentNode->count;
            }
            return score;
        }
    };
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> result;
        PrefixTree prefixTree;

        for (string& word : words) {
            prefixTree.insert(word);
        }
        for (string word : words) {
            result.push_back(prefixTree.getScore(word));
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<string> words = {"abc","ab","bc","b"};
    vector<int> result = solution.sumPrefixScores(words); // [5,4,3,2]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}