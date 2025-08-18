#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> doubleCards(cards.size());
        for (int i = 0; i < cards.size(); ++i) {
            doubleCards[i] = double(cards[i]);
        }
        return backtrack(doubleCards);
    }
private:
    static constexpr double epsion = 1e-6;
    bool backtrack(vector<double>& cards) {
        const int n = cards.size();
        if (n == 1) return fabs(cards[0] - 24) < epsion;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double a = cards[i], b = cards[j];

                vector<double> newCards;
                for (int k = 0; k < n; ++k) {
                    if (i == k || j == k) continue;
                    newCards.push_back(cards[k]);
                }

                vector<double> candidates { a + b, a - b, b - a, a * b };
                if (fabs(b) > epsion) candidates.push_back(a / b);
                if (fabs(a) > epsion) candidates.push_back(b / a);

                for (double value : candidates) {
                    newCards.push_back(value);
                    if (backtrack(newCards)) return true;
                    newCards.pop_back();
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution; 
    vector<int> cards = {4,1,8,7};
    cout << solution.judgePoint24(cards) << endl; // true
}