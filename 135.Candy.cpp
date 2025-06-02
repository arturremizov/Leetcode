#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        vector<int> candy(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i - 1] < ratings[i]) {
                candy[i] = candy[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1]) {
                candy[i] = candy[i + 1] + 1;
            }
        }
        
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += candy[i];
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> ratings = {1,0,2};
    cout << solution.candy(ratings) << endl; // 5
}