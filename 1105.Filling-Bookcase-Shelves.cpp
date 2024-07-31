#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        unordered_map<int, int> cache;
        return memo(books, shelfWidth, 0, cache);
    }
private:
    int memo(vector<vector<int>>& books, int shelfWidth, int i, unordered_map<int, int>& cache) {
        if (cache.count(i)) return cache[i];
        const int n = books.size();
        if (i == n) return 0;

        int currentWidth = shelfWidth;
        int maxHeight = 0;
        int result = INT_MAX;
        for (int j = i; j < n; ++j) {
            int width = books[j][0], height = books[j][1];

            if (currentWidth < width) break;
            currentWidth -= width;
            maxHeight = max(maxHeight, height);

            result = min(
                result, 
                memo(books, shelfWidth, j + 1, cache) + maxHeight
            );
        }
        cache[i] = result;
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> books = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    cout << solution.minHeightShelves(books, 4) << endl; // 6
}