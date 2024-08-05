#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> count;
        for (string str : arr) count[str]++;

        for (string str : arr) {
            if (count[str] == 1) {
                --k;
                if (k == 0) return str;
            }
        }
        return "";
    }
};

int main() {
    Solution solution; 
    vector<string> arr = {"d","b","c","b","c","a"};
    cout << solution.kthDistinct(arr, 2) << endl; // "a"
}