#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
private:
    static bool compare(int lhs, int rhs) {
        int lhsBits = countBits(lhs);
        int rhsBits = countBits(rhs);
        if (lhsBits == rhsBits) {
            return lhs < rhs;
        }
        return lhsBits < rhsBits;
    }
    static int countBits(int num) {
        int count = 0;
        while (num > 0) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }
};

int main() {
    Solution solution; 
    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    vector<int> result = solution.sortByBits(arr); // [0,1,2,4,8,3,5,6,7]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}