#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        const int n = deck.size();

        sort(deck.begin(), deck.end());
        vector<int> result(n);
        queue<int> queue;
        for (int i = 0; i < n; i++) {
            queue.push(i);
        }

        for (int card : deck) {
            int i = queue.front();
            queue.pop();
            result[i] = card;
            
            if (!queue.empty()) {
                int next = queue.front();
                queue.pop();
                queue.push(next);
            }
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> deck = {17,13,11,2,3,5,7};
    vector<int> result = solution.deckRevealedIncreasing(deck);
    for (int num : result) {
        cout << num << endl;
    }
}